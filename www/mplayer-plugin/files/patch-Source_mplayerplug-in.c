--- Source/mplayerplug-in.c.orig	Sat Apr 12 15:07:47 2003
+++ Source/mplayerplug-in.c	Sat Apr 12 15:08:56 2003
@@ -262,7 +262,7 @@
 	}
 
 	if (config == NULL) {
-		config = fopen("/etc/mplayerplug-in.conf","r");
+		config = fopen("%%PREFIX%%/etc/mplayerplug-in.conf","r");
 	}
 
 	DEBUG = 0;
