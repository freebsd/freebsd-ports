--- sys/xvideo/gstxvimage.c.orig	Sun Nov 23 20:17:00 2003
+++ sys/xvideo/gstxvimage.c	Sun Nov 23 20:25:19 2003
@@ -20,6 +20,10 @@
 #include "config.h"
 
 #include <errno.h>
+#include <sys/types.h>
+#include <machine/param.h>
+#include <sys/types.h>
+#include <sys/ipc.h>
 #include <sys/shm.h> /* for SHM symbols */
 #include <gst/gst.h>
 /* gcc -ansi -pedantic on GNU/Linux causes warnings and errors
@@ -34,7 +38,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <sys/types.h>
 
 #if defined (HAVE_IPC_H) && defined (HAVE_SHM_H) && defined (HAVE_XSHM_H)
 #define USE_SHM
