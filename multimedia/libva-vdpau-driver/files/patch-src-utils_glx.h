--- src/utils_glx.h.orig	2013-09-29 15:55:16.128603213 +0200
+++ src/utils_glx.h	2013-09-29 15:55:18.537925849 +0200
@@ -42,6 +42,19 @@
 typedef void (*PFNGLVDPAUUNMAPSURFACESNVPROC)(GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);
 #endif
 
+#if GL_GLEXT_VERSION >= 85
+/*
+ * The following typedef is hidden in at least Mesa 9.1.x, because:
+ *     o  GL/glext.h was updated to version 85, moving the typedef inside
+ *        an #ifndef GL_VERSION_1_3 block.
+ *        (Mesa Git: 68060cfb2bbf890a3932c8d25382261a83f393af)
+ *     o  GL/gl.h defines GL_VERSION_1_3 to 1.
+ *
+ * See: https://gitorious.org/vaapi/gstreamer-vaapi/commit/5db2e93d3c930fd8470cfdcd26f514d1cebc59a0/diffs
+ */
+typedef void (*PFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
+#endif
+
 /* GLX_EXT_texture_from_pixmap */
 #if GLX_GLXEXT_VERSION < 18
 typedef void (*PFNGLXBINDTEXIMAGEEXTPROC)(Display *, GLXDrawable, int, const int *);
