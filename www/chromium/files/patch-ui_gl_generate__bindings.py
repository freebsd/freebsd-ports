--- ui/gl/generate_bindings.py.orig	2020-03-03 18:54:06 UTC
+++ ui/gl/generate_bindings.py
@@ -2766,6 +2766,9 @@ GLX_FUNCTIONS = [
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
