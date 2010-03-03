--- tools/dahdi_monitor.c.orig	2009-04-21 20:44:58.000000000 +0700
+++ tools/dahdi_monitor.c	2010-03-03 17:24:25.000000000 +0600
@@ -40,7 +40,11 @@
 #include <dahdi/user.h>
 #include "dahdi_tools_version.h"
 
+#if defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#else
 #include <linux/soundcard.h>
+#endif
 
 /*
 * defines for file handle numbers
