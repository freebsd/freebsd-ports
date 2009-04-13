--- output.cc.orig	2009-04-01 00:29:03.000000000 +0200
+++ output.cc	2009-04-01 22:52:01.000000000 +0200
@@ -108,6 +108,7 @@
 #include <math.h>
 
 #include <set>
+#include <sys/param.h>
 #include <string>
 #include <vector>
 #include <list>
@@ -1030,8 +1031,8 @@
   case LOG_MACHINE:
   case LOG_SKID:
   case LOG_XML:
-#ifdef WIN32
-	  apcopy = ap;
+#if defined(WIN32) || (defined(FREEBSD) && (__FreeBSD_version < 500000))
+    apcopy = ap;
 #else
     va_copy(apcopy, ap); /* Needed in case we need to so a second vnsprintf */
 #endif
