--- server/vino-fb.c.orig	Mon Jul 12 06:22:08 2004
+++ server/vino-fb.c	Wed Jul 14 22:15:44 2004
@@ -37,6 +37,7 @@
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
