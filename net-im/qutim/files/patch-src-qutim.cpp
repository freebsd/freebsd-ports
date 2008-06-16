diff -ur qutIM/src/qutim.cpp qutIM.mine/src/qutim.cpp
--- src/qutim.cpp	2008-06-11 16:11:00.000000000 +0400
+++ src/qutim.cpp	2008-06-15 21:49:52.000000000 +0400
@@ -59,10 +59,10 @@
 	offlineList = NULL;
 	setAttribute(Qt::WA_AlwaysShowToolTips, true);
 	setFocus(Qt::ActiveWindowFocusReason);
+	createActions();
+	createTrayIcon();
 	if ( QSystemTrayIcon::isSystemTrayAvailable() )
 	{
-		createActions();
-		createTrayIcon();
 		trayIcon->show();
 		connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
 	             this, SLOT(trayActivated(QSystemTrayIcon::ActivationReason)));
