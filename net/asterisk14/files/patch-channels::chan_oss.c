
$FreeBSD$

--- channels/chan_oss.c.orig	Wed Oct 22 06:10:34 2003
+++ channels/chan_oss.c	Fri Jan 30 01:50:35 2004
@@ -36,7 +36,7 @@
 #ifdef __linux
 #include <linux/soundcard.h>
 #elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #include <soundcard.h>
 #endif
