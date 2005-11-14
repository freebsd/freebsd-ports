--- src/ncurses-gui.c.orig	Mon Nov 14 17:49:42 2005
+++ src/ncurses-gui.c	Mon Nov 14 18:01:48 2005
@@ -87,6 +87,12 @@
 #include "ncurses-gui.h"
 
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 500037
+#define resize_term resizeterm
+#endif
+#endif
 
 /*
  * Initialization routines for the GUI
