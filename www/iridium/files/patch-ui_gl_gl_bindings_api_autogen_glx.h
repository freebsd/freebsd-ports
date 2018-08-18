--- ui/gl/gl_bindings_api_autogen_glx.h.orig	2017-12-30 16:59:26.294402000 +0100
+++ ui/gl/gl_bindings_api_autogen_glx.h	2017-12-30 17:01:57.250690000 +0100
@@ -84,6 +84,7 @@
                         GLXDrawable drawable,
                         int32_t* numerator,
                         int32_t* denominator) override;
+__GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) override;
 void glXGetSelectedEventFn(Display* dpy,
                            GLXDrawable drawable,
                            unsigned long* mask) override;
