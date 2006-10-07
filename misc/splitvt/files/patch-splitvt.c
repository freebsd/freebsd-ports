--- splitvt.c.orig	Sat Jan 13 23:00:22 2001
+++ splitvt.c	Sat Oct  7 14:33:17 2006
@@ -21,6 +21,8 @@
 #include	<stdio.h>
 #include	<errno.h>
 #include	<pwd.h>
+#include	<stdlib.h>
+#include	<string.h>
 #ifdef HAVE_UNISTD_H
 #include	<unistd.h>
 #endif
