--- core/src/plugins/dird/python-dir.cc	2019-12-12 12:04:14.000000000 -0500
+++ core/src/plugins/dird/python-dir.cc	2019-12-29 00:20:30.334502000 -0500
@@ -35,6 +35,13 @@
 #error "Need at least Python version 2.6 or newer"
 #endif
 
+#if (PY_VERSION_HEX >  0x03050000)
+#define PyInt_AsLong PyLong_AsLong
+#define PyInt_FromLong PyLong_FromLong
+#define PyString_AsString PyUnicode_AsUTF8
+#define PyString_FromString PyUnicode_FromString
+#endif
+
 #include "python-dir.h"
 #include "lib/edit.h"
 
@@ -118,6 +125,20 @@
  */
 static PyThreadState *mainThreadState;
 
+#if (PY_VERSION_HEX >  0x03050000)
+static struct PyModuleDef BareosDIRModuleDef = {
+  PyModuleDef_HEAD_INIT,
+  "bareosdir",
+  NULL,
+  -1,
+  BareosDIRMethods,
+  NULL,
+  NULL,
+  NULL,
+  NULL
+};
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -679,7 +700,11 @@
       /*
        * Make our callback methods available for Python.
        */
+#if (PY_VERSION_HEX >  0x03050000)
+      p_ctx->pInstance = PyModule_Create(&BareosDIRModuleDef);
+#else
       p_ctx->pInstance = Py_InitModule("bareosdir", BareosDIRMethods);
+#endif
    }
 
    /*
@@ -959,7 +984,11 @@
       char *value;
 
       ctx = PyGetbpContext(pyCtx);
+#if (PY_VERSION_HEX >  0x03050000)
+      value = bstrdup(PyString_AsString(pyValue));
+#else
       value = PyString_AsString(pyValue);
+#endif
       if (value) {
          retval = bfuncs->setBareosValue(ctx, (bwDirVariable)var, value);
       }
