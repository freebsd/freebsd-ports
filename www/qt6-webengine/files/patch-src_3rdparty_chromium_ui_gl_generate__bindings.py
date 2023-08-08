--- src/3rdparty/chromium/ui/gl/generate_bindings.py.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/gl/generate_bindings.py
@@ -3000,6 +3000,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
