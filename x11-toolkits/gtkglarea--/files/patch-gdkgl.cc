--- gtkgl--/gdkgl.cc.orig	Wed Aug 28 13:56:43 2002
+++ gtkgl--/gdkgl.cc	Wed Aug 28 13:58:35 2002
@@ -69,7 +69,7 @@
 
 Gdk_GL::Context::Context(const Gdk_Visual &visual,
                         Context &share,
-                        bool direct=FALSE)
+                        bool direct)
   :Gdk_Handle<GdkGLContext>(0)
   {create(visual,share,direct);}
 
@@ -98,7 +98,7 @@
    ref();
   } 
 
-void Gdk_GL::Context::create(const Gdk_Visual &visual,Context &share,bool direct=FALSE)
+void Gdk_GL::Context::create(const Gdk_Visual &visual,Context &share,bool direct)
   {
    unref();
    obj_ = gdk_gl_context_share_new(gdk_const_cast(visual),share,direct);
