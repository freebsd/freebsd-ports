--- libs/domc/src/domc.h.orig	Tue Oct 17 01:25:18 2006
+++ libs/domc/src/domc.h	Wed Apr 11 09:38:08 2007
@@ -33,7 +33,9 @@
 #include <errno.h>
 #include <time.h>
 
-#if defined(__sparc__)
+#if defined(__FreeBSD__)
+  #include <inttypes.h>
+#elif defined(__sparc__)
   #include <sys/inttypes.h>
 #elif defined(_WIN32)
   typedef unsigned __int64 uint64_t;
