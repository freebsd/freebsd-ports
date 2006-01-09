--- kshutdown/configuration.cpp.orig	Mon Jan  9 18:40:46 2006
+++ kshutdown/configuration.cpp	Mon Jan  9 19:01:22 2006
@@ -31,7 +31,11 @@
 	// automation
 	setCurrentGroup("Automation");
 	i_cdTrayClose = addItemBool("cd_tray_close", cdTrayClose, false, "CDTrayClose");
+#ifdef Q_OS_FREEBSD
+	i_cdTrayCloseCommand = addItemString("cd_tray_close_command", cdTrayCloseCommand, "cdcontrol close", "CDTrayCloseCommand");
+#else
 	i_cdTrayCloseCommand = addItemString("cd_tray_close_command", cdTrayCloseCommand, "eject -t", "CDTrayCloseCommand");
+#endif
 
 	// custom message
 	setCurrentGroup("Custom Message");
