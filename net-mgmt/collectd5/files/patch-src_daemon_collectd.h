--- src/daemon/collectd.h.orig	2017-11-18 09:03:27 UTC
+++ src/daemon/collectd.h
@@ -207,7 +207,7 @@
 #endif
 
 #ifndef PKGLOCALSTATEDIR
-#define PKGLOCALSTATEDIR PREFIX "/var/lib/" PACKAGE_NAME
+#define PKGLOCALSTATEDIR PREFIX "/var/db/" PACKAGE_NAME
 #endif
 
 #ifndef PIDFILE
