--- sys/xvideo/gstxvimage.c.orig	Mon Oct 13 15:28:54 2003
+++ sys/xvideo/gstxvimage.c	Mon Oct 13 15:29:24 2003
@@ -20,6 +20,9 @@
 #include "config.h"
 
 #include <errno.h>
+#include <machine/param.h>
+#include <sys/types.h>
+#include <sys/ipc.h>
 #include <sys/shm.h> /* for SHM symbols */
 #include <gst/gst.h>
 /* gcc -ansi -pedantic on GNU/Linux causes warnings and errors
