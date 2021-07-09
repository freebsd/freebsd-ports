--- tensorflow/python/eager/pywrap_tfe_src.cc.orig	2021-07-07 11:59:05 UTC
+++ tensorflow/python/eager/pywrap_tfe_src.cc
@@ -1319,7 +1319,7 @@ static PyTypeObject TFE_Py_Tape_Type = {
     sizeof(TFE_Py_Tape),                          /* tp_basicsize */
     0,                                            /* tp_itemsize */
     &TFE_Py_Tape_Delete,                          /* tp_dealloc */
-    nullptr,                                      /* tp_print */
+    0,                                            /* tp_print */
     nullptr,                                      /* tp_getattr */
     nullptr,                                      /* tp_setattr */
     nullptr,                                      /* tp_reserved */
@@ -1353,7 +1353,7 @@ static PyTypeObject TFE_Py_ForwardAccumulator_Type = {
     sizeof(TFE_Py_ForwardAccumulator),                      /* tp_basicsize */
     0,                                                      /* tp_itemsize */
     &TFE_Py_ForwardAccumulatorDelete,                       /* tp_dealloc */
-    nullptr,                                                /* tp_print */
+    0,                                                      /* tp_print */
     nullptr,                                                /* tp_getattr */
     nullptr,                                                /* tp_setattr */
     nullptr,                                                /* tp_reserved */
