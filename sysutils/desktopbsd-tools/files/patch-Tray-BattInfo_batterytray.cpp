Index: Tray-BattInfo/batterytray.cpp
===================================================================
--- Tray-BattInfo/batterytray.cpp	(Revision 454)
+++ Tray-BattInfo/batterytray.cpp	(Revision 920)
@@ -1,7 +1,7 @@
 /* 
  * This file is part of DesktopBSD, see the README file.
  *
- * Author: Peter Hofer <hofer.p@gmail.com>
+ * Author: Peter Hofer <ph@desktopbsd.net>
  *         (C) 2004, 2005
  *
  * Copyright: BSD, see the COPYING file included in this distribution
@@ -26,14 +26,29 @@
 #define _UPDATE_MAX 30
 
 BatteryTray::BatteryTray() {
-	contextMenu()->insertItem(DBSDGlobal::getIconLoader()->loadIcon("configure", DBSDIconLoader::Size16x16),
+	DBSDIconLoader  *iloader = DBSDGlobal::getIconLoader();
+	
+	contextMenu()->insertItem(iloader->loadIcon("configure", DBSDIconLoader::Size16x16),
 	                          tr("Configure..."), this, SLOT(openConfigDialog()));
+	
+	imgBattery = iloader->loadIcon("dbsd-battinfo-battery", DBSDIconLoader::Size22x22)
+							.convertToImage();
+
+	imgRecharge = iloader->loadIcon("dbsd-battinfo-recharge", DBSDIconLoader::Size22x22)
+							.convertToImage();
+	
+	pixPower = iloader->loadIcon("dbsd-battinfo-power", DBSDIconLoader::Size22x22);
+	
+	previousRechargeLife = -1;
+	previousPowerSource = -1;
 }
 
 BatteryTray::~BatteryTray() {
 }
 
-void	BatteryTray::polish() {
+void	BatteryTray::showEvent(QShowEvent *e) {
+	KSystemTray::showEvent(e);
+
 	uint	updateTime = Battery::infoExpires();
 
 	/* Check for bad values and replace
@@ -44,7 +59,7 @@
 	else if(updateTime > _UPDATE_MAX)
 		updateTime = _UPDATE_MAX;
 
-	updateTime = 2;
+	updateStatus();
 
 	timer = new QTimer(this);
 	connect(timer,  SIGNAL(timeout()),  SLOT(updateStatus()));
@@ -53,33 +68,30 @@
 
 
 void  BatteryTray::updateStatus() {
-	DBSDIconLoader  *iloader = DBSDGlobal::getIconLoader();
 	QImage  image;
 	
 	static bool lifeCriticalShown = false,
 					lifeLowShown = false;
 
-	int  acline = Battery::powerSource();
+	int  powersrc = Battery::powerSource();
 	int  time = Battery::getTime();
 	int  life = Battery::getLife();
 
 	QString  tipText = tr("Power Source: %1\n", "The power source of a mobile device");
 
-	if(acline == Battery::PS_ACLine) {
+	if(powersrc == Battery::PS_ACLine) {
 		tipText = tipText.arg(tr("AC Line"));
 
 		if(life >= 0  &&  life  <= 100)
-			image = DBSDGlobal::getIconLoader()->loadIcon("dbsd-battinfo-recharge",
-																		 DBSDIconLoader::Size22x22).convertToImage();
+			image = imgRecharge;
 		else
-			setPixmap(iloader->loadIcon("dbsd-battinfo-power", DBSDIconLoader::Size22x22));
+			setPixmap(pixPower);
 
 		lifeCriticalShown = false;
 		lifeLowShown = false;
 	} else {
 		tipText = tipText.arg(tr("Battery"));
-		image = DBSDGlobal::getIconLoader()->loadIcon("dbsd-battinfo-battery",
-																	 DBSDIconLoader::Size22x22).convertToImage();
+		image = imgBattery;
 
 		if(!lifeCriticalShown) {
 			BatterySettings bs;
@@ -96,23 +108,36 @@
 	}
 
 	if(life >= 0 && life <= 100) {
-		for(uint y = 0;  y < (float) (image.height() - 9) / 100 * (100 - life) + 4;  ++y)
-			for(uint x = 0;  x < image.width();  ++x) {
-				uint rgba = image.pixel(x, y);
+		int rlife = (float) (image.height() - 9) / 100 * (101 - life) + 4;
+		
+		if(rlife != previousRechargeLife || powersrc != previousPowerSource)
+		{
+			image.detach();
 
-				/* Don't change transparent pixels */
-				if(qAlpha(rgba) < 190)
-					continue;
-			
-				QColor c;
-				int h, s ,v;
-				c.setRgb(rgba);
-				c.getHsv(&h, &s, &v);
-				c.setHsv(h, 0, ((v *= 1.1) > 255) ? 255 : v);
-				image.setPixel(x, y, c.rgb());
+			for(uint y = 0;  y < rlife;  ++y)
+			{
+				for(uint x = 0;  x < image.width();  ++x)
+				{
+					uint rgba = image.pixel(x, y);
+	
+					/* Don't change transparent pixels */
+					if(qAlpha(rgba) < 190)
+						continue;
+				
+					QColor c;
+					int h, s ,v;
+					c.setRgb(rgba);
+					c.getHsv(&h, &s, &v);
+					c.setHsv(h, 0, ((v *= 1.1) > 255) ? 255 : v);
+					image.setPixel(x, y, c.rgb());
+				}
 			}
 
-		setPixmap(QPixmap(image));
+			previousPowerSource = powersrc;
+			previousRechargeLife = rlife;
+			pixPreviousRecharge = image;
+			setPixmap(pixPreviousRecharge);
+		}
 
 		tipText += tr("Battery Status: %1 %\n").arg(life);
 	}
