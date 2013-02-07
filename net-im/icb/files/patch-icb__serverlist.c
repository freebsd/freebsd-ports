--- icb/serverlist.c.orig	2000-10-03 03:38:45.000000000 +0900
+++ icb/serverlist.c	2012-10-25 18:39:06.000000000 +0900
@@ -6,6 +6,9 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
 #ifdef HAVE_CTYPE_H
 #include <ctype.h>
 #endif
