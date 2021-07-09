--- tensorflow/python/lib/core/ndarray_tensor_bridge.cc.orig	2021-07-07 09:08:49 UTC
+++ tensorflow/python/lib/core/ndarray_tensor_bridge.cc
@@ -86,7 +86,7 @@ PyTypeObject TensorReleaserType = {
     0,                                /* tp_itemsize */
     /* methods */
     TensorReleaser_dealloc,      /* tp_dealloc */
-    nullptr,                     /* tp_print */
+    0,                           /* tp_print */
     nullptr,                     /* tp_getattr */
     nullptr,                     /* tp_setattr */
     nullptr,                     /* tp_compare */
