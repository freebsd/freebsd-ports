--- Source/mplayerplug-in.c.orig	Wed Sep 10 10:34:15 2003
+++ Source/mplayerplug-in.c	Mon Sep 29 00:43:56 2003
@@ -67,7 +67,7 @@
     }
 
     if (config == NULL) {
-	config = fopen("/etc/mplayerplug-in.conf", "r");
+	config = fopen("%%PREFIX%%/etc/mplayerplug-in.conf", "r");
     }
 
     if (config == NULL) {
