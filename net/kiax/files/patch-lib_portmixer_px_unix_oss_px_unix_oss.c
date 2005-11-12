--- lib/portmixer/px_unix_oss/px_unix_oss.c.orig	Sat Nov 12 17:36:03 2005
+++ lib/portmixer/px_unix_oss/px_unix_oss.c	Sat Nov 12 17:38:29 2005
@@ -38,7 +38,11 @@
 #ifdef __linux__
 #include <linux/soundcard.h>
 #else
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include <machine/soundcard.h> /* JH20010905 */
+#endif
 #endif
 
 #include <stdio.h>
