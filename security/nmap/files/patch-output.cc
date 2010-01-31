--- output.cc.orig	2009-12-20 04:22:19.000000000 +0100
+++ output.cc	2010-01-21 17:42:20.000000000 +0100
@@ -111,6 +111,7 @@
 #include <string>
 #include <vector>
 #include <list>
+#include <sys/param.h>
 
 /* Workaround for lack of namespace std on HP-UX 11.00 */
 namespace std {};
@@ -1037,7 +1038,7 @@
   case LOG_MACHINE:
   case LOG_SKID:
   case LOG_XML:
-#ifdef WIN32
+#if defined(WIN32) || (defined(FREEBSD) && (__FreeBSD_version < 500000))
     apcopy = ap;
 #else
     va_copy(apcopy, ap); /* Needed in case we need to do a second vsnprintf */
