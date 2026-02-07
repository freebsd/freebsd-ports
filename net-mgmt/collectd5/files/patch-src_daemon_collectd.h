--- src/daemon/collectd.h.orig	2019-06-13 09:13:42 UTC
+++ src/daemon/collectd.h
@@ -213,7 +213,7 @@ typedef int uid_t;
 #endif
 
 #ifndef PKGLOCALSTATEDIR
-#define PKGLOCALSTATEDIR PREFIX "/var/lib/" PACKAGE_NAME
+#define PKGLOCALSTATEDIR PREFIX "/var/db/" PACKAGE_NAME
 #endif
 
 #ifndef PIDFILE
