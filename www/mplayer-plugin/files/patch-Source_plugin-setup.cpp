--- Source/plugin-setup.cpp.orig	Fri Feb 13 09:45:47 2004
+++ Source/plugin-setup.cpp	Sun Feb 15 01:02:21 2004
@@ -2,7 +2,7 @@
 
 #ifndef STATICDECLS
 #define STATICDECLS
-int DEBUG = 1;
+int DEBUG = 0;
 int DESTROYED = 0;
 int enable_real;
 int enable_qt;
@@ -76,7 +76,7 @@
     }
 
     if (config == NULL) {
-	config = fopen("/etc/mplayerplug-in.conf", "r");
+	config = fopen("/usr/X11R6/etc/mplayerplug-in.conf", "r");
     }
 
     if (config == NULL) {
@@ -153,7 +153,7 @@
 	}
 
 	if (customtypes == NULL) {
-	    customtypes = fopen("/etc/mplayerplug-in.types", "r");
+	    customtypes = fopen("/usr/X11R6/etc/mplayerplug-in.types", "r");
 	}
 
 	if (customtypes != NULL) {
@@ -439,7 +439,7 @@
     }
 
     if (config == NULL) {
-	config = fopen("/etc/mplayerplug-in.conf", "r");
+	config = fopen("/usr/X11R6/etc/mplayerplug-in.conf", "r");
     }
 
     if (config == NULL) {
