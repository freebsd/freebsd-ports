--- mgp.h.orig	2008-01-18 17:43:20 UTC
+++ mgp.h
@@ -91,7 +91,7 @@
 #endif /* end of VFLIB */
 
 #ifdef FREETYPE
-#include "freetype.h"
+#include "freetype/freetype.h"
 
 #ifndef FREETYPEFONTDIR
 #define FREETYPEFONTDIR	"/usr/local/share/fonts/ttf"
@@ -853,3 +853,7 @@ extern void M17N_process_direc __P((char
 extern void M17N_draw_string __P((struct render_state *, struct ctrl *cp));
 extern void M17N_draw_object __P((struct render_object *, Drawable, int, int));
 #endif
+
+extern void mngload(char *mngfile, int x, int y, int width, int height);
+extern void mngpreload(struct render_state *state, char *mngfile, int *width, int *height);
+
