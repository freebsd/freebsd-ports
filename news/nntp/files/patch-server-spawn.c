--- server/spawn.c.orig	Fri Dec  9 03:53:14 1994
+++ server/spawn.c	Sun Aug 22 23:36:19 2004
@@ -5,9 +5,11 @@
 #include "common.h"
 
 #include <signal.h>
+#ifndef __FreeBSD__
 #ifdef sparc
 #ifndef SVR4
 #include <vfork.h>
+#endif
 #endif
 #endif
 #ifdef XFER_TIMEOUT
