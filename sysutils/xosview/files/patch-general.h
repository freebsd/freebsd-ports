--- general.h.orig	Fri Feb 14 01:22:03 1997
+++ general.h	Sun Dec  1 19:54:02 2002
@@ -17,11 +17,14 @@
       includes but before any local includes.  It should NOT be included
       by any .h files unless there is a REALLY good reason.  */
 
+#include "osreldate.h"
 
 #ifdef __GNUC__
+#if defined(__FreeBSD__) && (__FreeBSD_version < 500035)
   /*  Grab _G_HAVE_BOOL, if possible.  */
 #include <_G_config.h>
 #endif
+#endif
 
 #ifndef _G_HAVE_BOOL
   /*  Every GNU system has _G_config.h, I believe, which tells us
@@ -29,11 +32,6 @@
       let's just redefine them all.  The following lines are directly
       from g++-include's bool.h file.  bgrayson */
 
-#undef FALSE
-#undef false
-#undef TRUE
-#undef true
-enum bool { FALSE = 0, false = 0, TRUE = 1, true = 1 };
 #endif
 
 
