--- src/3rdparty/chromium/ui/gl/generate_bindings.py.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gl/generate_bindings.py
@@ -2902,6 +2902,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
