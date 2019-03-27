--- src/3rdparty/chromium/ui/gl/generate_bindings.py.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gl/generate_bindings.py
@@ -2350,6 +2350,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
