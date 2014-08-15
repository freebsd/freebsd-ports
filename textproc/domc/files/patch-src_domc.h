--- src/domc.h.orig	Thu Sep  9 23:52:10 2004
+++ src/domc.h	Sun Apr 10 22:14:52 2005
@@ -33,7 +33,7 @@
 #include <errno.h>
 #include <time.h>
 
-#if defined(__sparc__)
+#if 0 //defined(__sparc__)
   #include <sys/inttypes.h>
 #elif defined(_WIN32)
   typedef unsigned __int64 uint64_t;
