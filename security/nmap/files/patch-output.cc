--- ./output.cc.orig	2011-09-19 20:31:46.000000000 +0200
+++ ./output.cc	2011-09-23 22:11:50.000000000 +0200
@@ -114,6 +114,7 @@
 #include <set>
 #include <vector>
 #include <list>
+#include <sys/param.h>
 #include <sstream>
 
 /* Workaround for lack of namespace std on HP-UX 11.00 */
@@ -940,7 +941,7 @@
   case LOG_MACHINE:
   case LOG_SKID:
   case LOG_XML:
-#ifdef WIN32
+#if defined(WIN32) || (defined(FREEBSD) && (__FreeBSD_version < 500000))
     apcopy = ap;
 #else
     va_copy(apcopy, ap); /* Needed in case we need to do a second vsnprintf */
