--- ./katze/gtk3-compat.h.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./katze/gtk3-compat.h	2012-09-21 14:13:13.000000000 +0000
@@ -116,8 +116,11 @@
     #define GDK_KEY_Return GDK_Return
 #endif
 
-#ifndef GDK_IS_X11_DISPLAY
-    #define GDK_IS_X11_DISPLAY(display) TRUE
+#ifdef GDK_WINDOWING_X11
+    #include <gdk/gdkx.h>
+    #ifndef GDK_IS_X11_DISPLAY
+        #define GDK_IS_X11_DISPLAY(display) TRUE
+    #endif
 #endif
 
 G_END_DECLS
