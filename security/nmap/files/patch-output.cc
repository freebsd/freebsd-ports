--- output.cc.orig	Fri Dec  8 04:01:19 2006
+++ output.cc	Wed Jan  3 17:10:43 2007
@@ -109,6 +109,7 @@
 #include "NmapOutputTable.h"
 #include "MACLookup.h"
 
+#include <sys/param.h>
 #include <string>
 
 /* Workaround for lack of namespace std on HP-UX 11.00 */
@@ -742,8 +743,8 @@
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
