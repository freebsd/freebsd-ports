--- Source/mplayerplug-in.c.orig	Fri Feb 21 15:43:56 2003
+++ Source/mplayerplug-in.c	Fri Feb 21 15:44:24 2003
@@ -219,7 +219,7 @@
 	}
 
 	if (config == NULL) {
-		config = fopen("/etc/mplayerplug-in.conf","r");
+		config = fopen("%%PREFIX%%/etc/mplayerplug-in.conf","r");
 	}
 
 	DEBUG = 0;
