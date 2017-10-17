--- ui/gl/generate_bindings.py.orig	2017-09-10 02:49:38.177014000 +0200
+++ ui/gl/generate_bindings.py	2017-09-10 02:52:26.524647000 +0200
@@ -2257,6 +2257,9 @@
   'arguments':
       'Display* dpy, GLXDrawable drawable, int32_t* numerator, '
       'int32_t* denominator' },
+{ 'return_type': '__GLXextFuncPtr',
+  'names': ['glXGetProcAddressARB'],
+  'arguments': 'const GLubyte* procName', },
 { 'return_type': 'void',
   'names': ['glXGetSelectedEvent'],
   'arguments': 'Display* dpy, GLXDrawable drawable, unsigned long* mask', },
