--- icb/tcl.c.orig	2000-10-02 20:25:55.000000000 +0900
+++ icb/tcl.c	2012-10-25 18:22:17.000000000 +0900
@@ -3,6 +3,9 @@
 /* TCL interface */
 #include "config.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
