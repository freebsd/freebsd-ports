--- pinentry/pinentry.c.orig	Thu Jan 30 08:36:45 2003
+++ pinentry/pinentry.c	Thu Jan 30 08:37:10 2003
@@ -22,6 +22,10 @@
 #include <config.h>
 #endif
 
+#ifdef _GETOPT_H
+#undef _GETOPT_H
+#endif
+
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
