--- va/glx/va_glx_private.h.orig	2017-10-21 04:49:28 UTC
+++ va/glx/va_glx_private.h
@@ -38,7 +38,7 @@ typedef void (*PFNGLXBINDTEXIMAGEEXTPROC)(Display *, G
 typedef void (*PFNGLXRELEASETEXIMAGEEXTPROC)(Display *, GLXDrawable, int);
 #endif
 
-#if GLX_GLXEXT_VERSION < 27
+#if GLX_GLXEXT_VERSION < 21
 /* XXX: this is not exactly that version but this is the only means to
    make sure we have the correct <GL/glx.h> with those signatures */
 typedef GLXPixmap (*PFNGLXCREATEPIXMAPPROC)(Display *, GLXFBConfig, Pixmap, const int *);
