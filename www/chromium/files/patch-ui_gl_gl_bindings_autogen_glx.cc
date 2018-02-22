--- ui/gl/gl_bindings_autogen_glx.cc.orig	2017-12-15 02:04:52.000000000 +0100
+++ ui/gl/gl_bindings_autogen_glx.cc	2017-12-30 20:41:29.231707000 +0100
@@ -73,6 +73,7 @@
   fn.glXGetFBConfigsFn = reinterpret_cast<glXGetFBConfigsProc>(
       GetGLProcAddress("glXGetFBConfigs"));
   fn.glXGetMscRateOMLFn = 0;
+  fn.glXGetProcAddressARBFn = 0;
   fn.glXGetSelectedEventFn = reinterpret_cast<glXGetSelectedEventProc>(
       GetGLProcAddress("glXGetSelectedEvent"));
   fn.glXGetSyncValuesOMLFn = 0;
@@ -120,6 +121,8 @@
 
   ext.b_GLX_ARB_create_context =
       HasExtension(extensions, "GLX_ARB_create_context");
+  ext.b_GLX_ARB_get_proc_address =
+      HasExtension(extensions, "GLX_ARB_get_proc_address");
   ext.b_GLX_EXT_swap_control = HasExtension(extensions, "GLX_EXT_swap_control");
   ext.b_GLX_EXT_texture_from_pixmap =
       HasExtension(extensions, "GLX_EXT_texture_from_pixmap");
@@ -147,6 +150,11 @@
             GetGLProcAddress("glXCreateContextAttribsARB"));
   }
 
+  if (ext.b_GLX_ARB_get_proc_address) {
+    fn.glXGetProcAddressARBFn = reinterpret_cast<glXGetProcAddressARBProc>(
+        GetGLProcAddress("glXGetProcAddressARB"));
+  }
+
   if (ext.b_GLX_SGIX_fbconfig) {
     fn.glXGetFBConfigFromVisualSGIXFn =
         reinterpret_cast<glXGetFBConfigFromVisualSGIXProc>(
@@ -348,6 +356,10 @@
   return driver_->fn.glXGetMscRateOMLFn(dpy, drawable, numerator, denominator);
 }
 
+__GLXextFuncPtr GLXApiBase::glXGetProcAddressARBFn(const GLubyte* procName) {
+  return driver_->fn.glXGetProcAddressARBFn(procName);
+}
+
 void GLXApiBase::glXGetSelectedEventFn(Display* dpy,
                                        GLXDrawable drawable,
                                        unsigned long* mask) {
@@ -648,6 +660,11 @@
   return glx_api_->glXGetMscRateOMLFn(dpy, drawable, numerator, denominator);
 }
 
+__GLXextFuncPtr TraceGLXApi::glXGetProcAddressARBFn(const GLubyte* procName) {
+  TRACE_EVENT_BINARY_EFFICIENT0("gpu", "TraceGLAPI::glXGetProcAddressARB")
+  return glx_api_->glXGetProcAddressARBFn(procName);
+}
+
 void TraceGLXApi::glXGetSelectedEventFn(Display* dpy,
                                         GLXDrawable drawable,
                                         unsigned long* mask) {
@@ -1070,6 +1087,14 @@
                  << static_cast<const void*>(denominator) << ")");
   bool result =
       glx_api_->glXGetMscRateOMLFn(dpy, drawable, numerator, denominator);
+  GL_SERVICE_LOG("GL_RESULT: " << result);
+  return result;
+}
+
+__GLXextFuncPtr DebugGLXApi::glXGetProcAddressARBFn(const GLubyte* procName) {
+  GL_SERVICE_LOG("glXGetProcAddressARB"
+                 << "(" << static_cast<const void*>(procName) << ")");
+  __GLXextFuncPtr result = glx_api_->glXGetProcAddressARBFn(procName);
   GL_SERVICE_LOG("GL_RESULT: " << result);
   return result;
 }
