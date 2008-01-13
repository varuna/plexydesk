#include "widgetitem.h"
#include <QtCore>
#include <QtGui>

namespace PlexyDesk
{
    WidgetItem::WidgetItem(const QRectF &rect, QWidget *widget ):DesktopWidget(rect)
    {
		dateImg = QImage(160,160,QImage::Format_ARGB32_Premultiplied);
		dateImg.fill(Qt::transparent);
		QPainter p;
		p.begin(&dateImg);
		p.setPen(QColor(215,255,98));
		p.setFont(QFont("Bitstream Charter",20));
		p.drawText(QRect(20,20,160,160), Qt::AlignTop ,QDate::longDayName(QDate::currentDate().dayOfWeek ())  ) ;
		p.setFont(QFont("Bitstream Charter",50));
		p.drawText(QRect(40,40,160,160), Qt::AlignTop ,QString("%1").arg(QDate::currentDate().day() )  )  ;
		p.end();
	
    }
    
    WidgetItem::~WidgetItem()
    {

    }

    void WidgetItem::paintExtFace(QPainter *p, const QStyleOptionGraphicsItem * e , QWidget * widget)
    {
		p->setRenderHints(QPainter::SmoothPixmapTransform |QPainter::Antialiasing |QPainter::HighQualityAntialiasing);
		p->drawImage(e->exposedRect,dateImg);

    }


    QRectF WidgetItem::boundingRect() const
    {
        return rect();
    }

} // namespace PlexyDesk

#include "widgetitem.moc"