--- Source/mplayerplug-in.c.orig	Fri Oct  3 07:54:52 2003
+++ Source/mplayerplug-in.c	Sun Oct  5 00:02:12 2003
@@ -71,7 +71,7 @@
     }
 
     if (config == NULL) {
-	config = fopen("/etc/mplayerplug-in.conf", "r");
+	config = fopen("%%PREFIX%%/etc/mplayerplug-in.conf", "r");
     }
 
     if (config == NULL) {
@@ -148,7 +148,7 @@
 	}
 
 	if (customtypes == NULL) {
-	    customtypes = fopen("/etc/mplayerplug-in.types", "r");
+	    customtypes = fopen("%%PREFIX%%/etc/mplayerplug-in.types", "r");
 	}
 
 	if (customtypes != NULL) {
