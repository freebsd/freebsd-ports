
$FreeBSD$

--- apps/app_intercom.c.orig	Wed Aug 13 18:25:16 2003
+++ apps/app_intercom.c	Fri Oct 17 11:27:30 2003
@@ -29,7 +29,7 @@
 #ifdef __linux__
 #include <linux/soundcard.h>
 #else
-#include <soundcard.h>
+#include <sys/soundcard.h>
 #endif
 #include <netinet/in.h>
 
