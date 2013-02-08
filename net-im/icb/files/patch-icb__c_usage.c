--- icb/c_usage.c.orig	2000-10-02 20:25:42.000000000 +0900
+++ icb/c_usage.c	2012-10-25 18:29:43.000000000 +0900
@@ -6,6 +6,10 @@
 #include "icb.h"
 #include "externs.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 int
 c_usage (ARGV_TCL)
 {
