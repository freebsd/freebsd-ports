--- libretroshare/src/util/rsdiscspace.cc.orig	2011-07-05 00:59:39.000000000 +0200
+++ libretroshare/src/util/rsdiscspace.cc	2012-01-15 04:55:17.000000000 +0100
@@ -31,6 +31,7 @@
 #include <util/rsthreads.h>
 #ifndef WIN32
 #include <sys/statvfs.h>
+#define statvfs64 statvfs
 #endif
 
 #define DELAY_BETWEEN_CHECKS 2 
