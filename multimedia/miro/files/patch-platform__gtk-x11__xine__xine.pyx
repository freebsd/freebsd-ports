--- platform/gtk-x11/xine/xine.pyx.orig	2010-05-08 21:58:50.000000000 +0200
+++ platform/gtk-x11/xine/xine.pyx	2010-05-08 21:59:10.000000000 +0200
@@ -89,7 +89,7 @@
     cdef _Xine* xine
     cdef object eosCallback
 
-    def __new__(self):
+    def __cinit__(self):
         self.xine = xineCreate(on_xine_event, <void*>self)
         self.eosCallback = None
     def __dealloc__(self):
