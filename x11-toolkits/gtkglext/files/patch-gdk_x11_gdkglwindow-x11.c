--- gdk/x11/gdkglwindow-x11.c.orig	Sat May  3 21:50:19 2003
+++ gdk/x11/gdkglwindow-x11.c	Sat May  3 21:50:44 2003
@@ -95,7 +95,7 @@
 void
 _gdk_gl_window_destroy (GdkGLWindow *glwindow)
 {
-  GdkGLWindowImplX11 *impl = GDK_GL_WINDOW_IMPL_X11 (glwindow);;
+  GdkGLWindowImplX11 *impl = GDK_GL_WINDOW_IMPL_X11 (glwindow);
   Display *xdisplay;
   GdkGL_GLX_MESA_release_buffers *mesa_ext;
 
