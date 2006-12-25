--- ./misc-utils/rename.c.orig	Tue May  9 23:39:03 2000
+++ ./misc-utils/rename.c	Mon Dec 25 14:54:11 2006
@@ -19,6 +19,8 @@
 #include <errno.h>
 #include "nls.h"
 
+#define util_linux_version "util-linux-2.12r"
+
 static char *progname;
 
 static int
