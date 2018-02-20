--- ui/gl/gl_bindings_autogen_glx.h.orig	2017-12-15 02:04:52.000000000 +0100
+++ ui/gl/gl_bindings_autogen_glx.h	2017-12-30 20:37:25.644088000 +0100
@@ -104,6 +104,8 @@
                                                     GLXDrawable drawable,
                                                     int32_t* numerator,
                                                     int32_t* denominator);
+typedef __GLXextFuncPtr(GL_BINDING_CALL* glXGetProcAddressARBProc)(
+    const GLubyte* procName);
 typedef void(GL_BINDING_CALL* glXGetSelectedEventProc)(Display* dpy,
                                                        GLXDrawable drawable,
                                                        unsigned long* mask);
@@ -166,6 +168,7 @@
 
 struct ExtensionsGLX {
   bool b_GLX_ARB_create_context;
+  bool b_GLX_ARB_get_proc_address;
   bool b_GLX_EXT_swap_control;
   bool b_GLX_EXT_texture_from_pixmap;
   bool b_GLX_MESA_copy_sub_buffer;
@@ -203,6 +206,7 @@
   glXGetFBConfigFromVisualSGIXProc glXGetFBConfigFromVisualSGIXFn;
   glXGetFBConfigsProc glXGetFBConfigsFn;
   glXGetMscRateOMLProc glXGetMscRateOMLFn;
+  glXGetProcAddressARBProc glXGetProcAddressARBFn;
   glXGetSelectedEventProc glXGetSelectedEventFn;
   glXGetSyncValuesOMLProc glXGetSyncValuesOMLFn;
   glXGetVisualFromFBConfigProc glXGetVisualFromFBConfigFn;
@@ -310,6 +314,7 @@
                                   GLXDrawable drawable,
                                   int32_t* numerator,
                                   int32_t* denominator) = 0;
+  virtual __GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) = 0;
   virtual void glXGetSelectedEventFn(Display* dpy,
                                      GLXDrawable drawable,
                                      unsigned long* mask) = 0;
@@ -394,6 +399,7 @@
   ::gl::g_current_glx_context->glXGetFBConfigFromVisualSGIXFn
 #define glXGetFBConfigs ::gl::g_current_glx_context->glXGetFBConfigsFn
 #define glXGetMscRateOML ::gl::g_current_glx_context->glXGetMscRateOMLFn
+#define glXGetProcAddressARB ::gl::g_current_glx_context->glXGetProcAddressARBFn
 #define glXGetSelectedEvent ::gl::g_current_glx_context->glXGetSelectedEventFn
 #define glXGetSyncValuesOML ::gl::g_current_glx_context->glXGetSyncValuesOMLFn
 #define glXGetVisualFromFBConfig \
