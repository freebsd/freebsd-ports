--- gui.c.orig	Sun Dec  4 14:32:24 2005
+++ gui.c	Sun Dec  4 14:33:20 2005
@@ -3,11 +3,11 @@
 #include "gfx/mask.xpm"
 #include "gopod.h"
 
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
 #define SQUARE(x) ((x)*(x))
 
 GtkWidget *pWindow;
