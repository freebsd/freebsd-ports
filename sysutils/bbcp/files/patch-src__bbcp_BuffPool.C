--- src/bbcp_BuffPool.C.orig	2015-01-14 12:12:20.000000000 -0800
+++ src/bbcp_BuffPool.C	2015-01-14 12:24:14.000000000 -0800
@@ -32,7 +32,7 @@
 #include <inttypes.h>
 #include <sys/mman.h>
 
-#if defined(MACOS) || defined(AIX)
+#if defined(MACOS) || defined(FREEBSD)
 #define memalign(pgsz,amt) valloc(amt)
 #else
 #include <malloc.h>
