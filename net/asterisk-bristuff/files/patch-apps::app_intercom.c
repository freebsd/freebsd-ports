
$FreeBSD$

--- apps/app_intercom.c.orig	Wed Oct 22 06:10:24 2003
+++ apps/app_intercom.c	Fri Jan 30 01:52:03 2004
@@ -29,7 +29,7 @@
 #ifdef __linux__
 #include <linux/soundcard.h>
 #elif defined(__FreeBSD__)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #include <soundcard.h>
 #endif
