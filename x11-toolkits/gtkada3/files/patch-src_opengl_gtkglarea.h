--- src/opengl/gtkglarea.h.orig	2016-05-12 07:43:49 UTC
+++ src/opengl/gtkglarea.h
@@ -21,6 +21,9 @@
 #ifndef __GTK_GL_AREA_H__
 #define __GTK_GL_AREA_H__
 
+typedef struct _GtkGLArea       GtkGLArea;
+typedef struct _GtkGLAreaClass  GtkGLAreaClass;
+
 #include <gdk/gdk.h>
 #include <gdkgl.h>
 #include <gtk/gtk.h>
@@ -36,9 +39,6 @@ G_BEGIN_DECLS
 #define GTK_GL_AREA_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_GL_AREA, GtkGLArea))
 
 
-typedef struct _GtkGLArea       GtkGLArea;
-typedef struct _GtkGLAreaClass  GtkGLAreaClass;
-
 
 struct _GtkGLArea
 {
