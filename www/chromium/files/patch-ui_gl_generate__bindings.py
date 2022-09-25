--- ui/gl/generate_bindings.py.orig	2022-09-24 10:57:32 UTC
+++ ui/gl/generate_bindings.py
@@ -2933,6 +2933,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
