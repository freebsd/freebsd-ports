--- icb/s_user.c.orig	2000-10-02 20:25:52.000000000 +0900
+++ icb/s_user.c	2012-10-25 18:33:46.000000000 +0900
@@ -6,6 +6,10 @@
 #include "icb.h"
 #include "externs.h"
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 int
 s_user (ARGV_TCL)
 {
