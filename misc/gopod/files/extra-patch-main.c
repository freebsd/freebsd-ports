--- main.c.orig	Tue Oct 25 10:57:30 2005
+++ main.c	Tue Oct 25 10:59:23 2005
@@ -5,11 +5,11 @@
 #include <gtk/gtk.h>
 #include "gfx/mask.xpm"
 
-#define GFX_GO "gfx/go.png"
-#define GFX_GO_ "gfx/go_.png"
-#define GFX_NOTDETECTED "gfx/notdetected.png"
-#define GFX_CAPPED "gfx/capped.png"
-#define GFX_UNCAPPED "gfx/uncapped.png"
+#define GFX_GO "%%DATADIR%%/go.png"
+#define GFX_GO_ "%%DATADIR%%/go_.png"
+#define GFX_NOTDETECTED "%%DATADIR%%/notdetected.png"
+#define GFX_CAPPED "%%DATADIR%%/capped.png"
+#define GFX_UNCAPPED "%%DATADIR%%/uncapped.png"
 
 #if defined(__LINUX__)
 #define DEV "/dev/sd%c"
