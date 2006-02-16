--- src/dialogs/document.c.orig	Tue Feb 14 13:42:17 2006
+++ src/dialogs/document.c	Tue Feb 14 13:43:00 2006
@@ -1,5 +1,9 @@
 /* Information about current document and current link */
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+#define	PRId64		"lld"
+#endif
+
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
