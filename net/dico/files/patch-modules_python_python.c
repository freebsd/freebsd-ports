--- modules/python/python.c.orig	2024-10-15 09:34:20 UTC
+++ modules/python/python.c
@@ -100,7 +100,7 @@ _PySelectionKey_str (PyObject *self)
 }
 
 static PyTypeObject PySelectionKeyType = {
-    PyObject_HEAD_INIT(&PyType_Type)
+    PyVarObject_HEAD_INIT(&PyType_Type, 0)
     .tp_name = "DicoSelectionKey",
     .tp_basicsize = sizeof (PySelectionKey),
     .tp_dealloc = _PySelectionKey_dealloc,
@@ -185,7 +185,7 @@ _PyStrategy_str (PyObject *self)
 }
 
 static PyTypeObject PyStrategyType = {
-    PyObject_HEAD_INIT(&PyType_Type)
+    PyVarObject_HEAD_INIT(&PyType_Type, 0)
     .tp_name = "DicoStrategy",
     .tp_basicsize = sizeof (PyStrategy),
     .tp_dealloc = _PyStrategy_dealloc,
