--- systemconfig.cpp.orig	2009-01-24 18:36:05.000000000 +1300
+++ kshutdown/systemconfig.cpp	2009-01-24 18:34:34.000000000 +1300
@@ -90,7 +90,7 @@
 
 	_shutdownAllowItem = add(Info, i18n("Tip: Click here if you have problem with the \"/sbin/shutdown\" command."));
 
-	checkFile("/sbin/poweroff");
+	checkFile("/sbin/halt");
 	checkFile("/sbin/reboot");
 	checkFile("/sbin/shutdown");
 	checkKDM();
