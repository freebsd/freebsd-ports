--- binread.c.orig	2009-06-18 16:05:29.000000000 +0200
+++ binread.c	2009-06-18 16:06:26.000000000 +0200
@@ -35,8 +35,13 @@
 #if defined (linux) || defined(__APPLE__)
 #define __FAVOR_BSD
 #else
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 800064
 #include <net/slip.h>
 #endif
+#endif
+#endif
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <net/if.h>
