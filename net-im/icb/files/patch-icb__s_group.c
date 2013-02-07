--- icb/s_group.c.orig	2000-10-02 20:25:51.000000000 +0900
+++ icb/s_group.c	2012-10-25 18:32:57.000000000 +0900
@@ -6,6 +6,10 @@
 #include "icb.h"
 #include "externs.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 int
 s_group (ARGV_TCL)
 {
