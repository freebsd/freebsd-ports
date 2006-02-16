--- src/cache/cache.c.orig	Tue Feb 14 13:41:35 2006
+++ src/cache/cache.c	Tue Feb 14 13:41:49 2006
@@ -1,5 +1,9 @@
 /* Cache subsystem */
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+#define	PRId64		"lld"
+#endif
+
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
