--- src/callbacks.c.orig	Sat Nov 24 07:38:45 2001
+++ src/callbacks.c	Sat Nov 24 16:22:22 2001
@@ -2,12 +2,22 @@
 #  include <config.h>
 #endif
 
+#ifdef HAVE_SYS_PARAM_H
+#  include <sys/param.h>
+#endif
+
 #include <math.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <gdk/gdkkeysyms.h>
+#if !(defined(BSD) && (BSD >= 199103)) /* !BSD */
 #include <linux/sem.h>
+#endif
 #include <gnome.h>
+
+#ifndef SEMVMX
+#define SEMVMX	32767
+#endif
 
 #include "callbacks.h"
 #include "interface.h"
