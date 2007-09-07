Index: Tray-BattInfo/batterytray.h
===================================================================
--- Tray-BattInfo/batterytray.h	(Revision 454)
+++ Tray-BattInfo/batterytray.h	(Revision 920)
@@ -1,7 +1,7 @@
 /* 
  * This file is part of DesktopBSD, see the README file.
  *
- * Author: Peter Hofer <hofer.p@gmail.com>
+ * Author: Peter Hofer <ph@desktopbsd.net>
  *         (C) 2004, 2005
  *
  * Copyright: BSD, see the COPYING file included in this distribution
@@ -11,10 +11,13 @@
 #ifndef __BATTERYTRAY_H
 #define __BATTERYTRAY_H
 
-#include <qtimer.h>
 #include <ksystemtray.h>
+
+#include <qpixmap.h>
 #include <qimage.h>
 
+class QTimer;
+
 class BatteryTray : public KSystemTray {
    Q_OBJECT
    
@@ -23,11 +26,10 @@
    virtual	~BatteryTray();
    
 public slots:
-	virtual void	polish();
-	
    void	updateStatus();
 
 protected:
+	virtual void showEvent(QShowEvent *e);
 	virtual void mouseDoubleClickEvent(QMouseEvent *e);
 
 protected slots:
@@ -35,6 +37,9 @@
    
 private:
 	QTimer	*timer;
+	QImage	imgBattery, imgRecharge;
+	QPixmap	pixPower, pixPreviousRecharge;
+	int		previousRechargeLife, previousPowerSource;
 };
 
 #endif /* __BATTERYTRAY_H */
