--- src/mediactrl.h.orig	Mon Mar 15 21:25:09 2004
+++ src/mediactrl.h	Sun Apr 11 02:52:17 2004
@@ -153,6 +153,8 @@
 
 };
 
+struct input_event {
+};
 
 struct media_ctrl_device {
 	int vendor;
