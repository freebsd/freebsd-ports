--- src/x11.c.orig
+++ src/x11.c
@@ -44,7 +44,7 @@
 
 #ifdef XFT
 #include <X11/Xft/Xft.h>
-int use_xft = 0;
+int use_xft;
 #endif
 
 #ifdef HAVE_XDBE
@@ -336,7 +336,7 @@ void init_window(int own_window, int w, int h, int set_trans, int back_colour,
 			XClassHint classHint;
 			XWMHints wmHint;
 			Atom xa;
-			
+
 #ifdef USE_ARGB
 			if (have_argb_visual) {
 				attrs.colormap = window.colourmap;
@@ -775,13 +775,14 @@ void get_x11_desktop_info(Display *current_display, Atom atom)
 	}
 }
 
-void update_x11info(void)
+int update_x11info(void)
 {
 	struct information *current_info = &info;
 	if (x_initialised != YES)
-		return;
+		return 0;
 	current_info->x11.monitor.number = XScreenCount(display);
 	current_info->x11.monitor.current = XDefaultScreen(display);
+	return 0;
 }
 
 #ifdef OWN_WINDOW
