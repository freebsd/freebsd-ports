--- calendar/libical/src/libical/icalrecur.c.orig	Thu Mar 17 07:13:54 2005
+++ calendar/libical/src/libical/icalrecur.c	Thu Mar 17 07:14:30 2005
@@ -134,9 +134,7 @@
 #include "config.h"
 #endif
 
-#ifdef HAVE_STDINT_H
-#include <stdint.h>
-#endif
+#include <inttypes.h>
 
 #ifndef HAVE_INTPTR_T
 #ifdef WIN32
