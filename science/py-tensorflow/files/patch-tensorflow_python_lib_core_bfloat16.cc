--- tensorflow/python/lib/core/bfloat16.cc.orig	2021-07-07 11:57:12 UTC
+++ tensorflow/python/lib/core/bfloat16.cc
@@ -317,7 +317,7 @@ PyTypeObject PyBfloat16_Type = {
     sizeof(PyBfloat16),                        // tp_basicsize
     0,                                         // tp_itemsize
     nullptr,                                   // tp_dealloc
-    nullptr,                                   // tp_print
+    0,                                         // tp_print
     nullptr,                                   // tp_getattr
     nullptr,                                   // tp_setattr
     nullptr,                                   // tp_compare / tp_reserved
