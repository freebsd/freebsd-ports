--- src/cache/dialogs.c.orig	Tue Feb 14 13:38:58 2006
+++ src/cache/dialogs.c	Tue Feb 14 13:39:53 2006
@@ -4,6 +4,10 @@
 #define _GNU_SOURCE /* XXX: we _WANT_ strcasestr() ! */
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+#define	PRId64		"lld"
+#endif
+
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
