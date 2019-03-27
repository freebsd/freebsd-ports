--- src/3rdparty/chromium/ui/gl/gl_bindings_api_autogen_glx.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gl/gl_bindings_api_autogen_glx.h
@@ -84,6 +84,7 @@ bool glXGetMscRateOMLFn(Display* dpy,
                         GLXDrawable drawable,
                         int32_t* numerator,
                         int32_t* denominator) override;
+__GLXextFuncPtr glXGetProcAddressARBFn(const GLubyte* procName) override;
 void glXGetSelectedEventFn(Display* dpy,
                            GLXDrawable drawable,
                            unsigned long* mask) override;
