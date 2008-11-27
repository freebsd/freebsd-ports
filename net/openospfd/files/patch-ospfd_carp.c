--- ospfd/carp.c.orig	2008-02-07 18:26:32.000000000 +0300
+++ ospfd/carp.c	2008-02-07 18:39:58.000000000 +0300
@@ -29,6 +29,13 @@
 #include "ospfd.h"
 #include "log.h"
 
+#if defined(__FreeBSD__) /* XXX: FreeBSD has no CARP demotion support */
+
+#warning "CARP demotion is not supported for FreeBSD."
+#warning "Demotion code is disconnected from the build."
+
+#else
+
 struct carpgroup {
 	TAILQ_ENTRY(carpgroup)	 entry;
 	char			*group;
@@ -179,3 +186,5 @@
 	close(s);
 	return (res);
 }
+
+#endif /* defined(__FreeBSD__) */
