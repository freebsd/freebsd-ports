--- playdv/display.c.orig	Sun Jun 24 13:06:30 2001
+++ playdv/display.c	Mon Nov 19 00:37:55 2001
@@ -47,6 +47,8 @@
 #include <popt.h>
 #endif
 
+dv_display_t 	*dv_dpy_on_exit_hack;
+
 static int      dv_display_SDL_init(dv_display_t *dv_dpy, gchar *w_name, gchar   *i_name           );
 static gboolean dv_display_gdk_init(dv_display_t *dv_dpy, gint  *argc,   gchar ***argv             );
 
@@ -675,6 +677,13 @@
   } /* if */
 } /* dv_display_exit_handler */
 
+static void
+dv_display_on_exit_hack_handler()
+{
+  if(dv_dpy_on_exit_hack) {
+    dv_display_exit(dv_dpy_on_exit_hack);
+  } /* if */
+} /* dv_display_exit_handler */
 
 gboolean
 dv_display_init(dv_display_t *dv_dpy, gint *argc, gchar ***argv, gint width, gint height, 
@@ -804,7 +813,8 @@
   fprintf(stderr, " Using gtk for display\n");
 
  ok:
-  on_exit(dv_display_exit_handler, dv_dpy);
+  dv_dpy_on_exit_hack = dv_dpy;
+  atexit(dv_display_on_exit_hack_handler);
   return(TRUE);
 
  fail:
