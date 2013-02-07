--- icb/s_who.c.orig	2000-10-02 20:25:53.000000000 +0900
+++ icb/s_who.c	2012-10-25 18:34:37.000000000 +0900
@@ -6,6 +6,10 @@
 #include "icb.h"
 #include "externs.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 int
 s_who (ARGV_TCL)
 {
