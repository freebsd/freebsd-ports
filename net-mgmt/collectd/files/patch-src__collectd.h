--- ./src/collectd.h.orig	2007-09-28 17:55:34.000000000 +0300
+++ ./src/collectd.h	2008-05-06 10:32:08.000000000 +0300
@@ -183,7 +183,7 @@
 #endif
 
 #ifndef LOCALSTATEDIR
-#define LOCALSTATEDIR PREFIX "/var"
+#define LOCALSTATEDIR "/var"
 #endif
 
 #ifndef PKGLOCALSTATEDIR
@@ -191,7 +191,7 @@
 #endif
 
 #ifndef PIDFILE
-#define PIDFILE PREFIX "/var/run/" PACKAGE_NAME ".pid"
+#define PIDFILE "/var/run/" PACKAGE_NAME ".pid"
 #endif
 
 #ifndef PLUGINDIR
