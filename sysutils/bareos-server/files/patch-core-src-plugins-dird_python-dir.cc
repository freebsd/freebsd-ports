--- core/src/plugins/dird/python-dir.cc	2020-01-31 11:21:18.000000000 -0500
+++ core/src/plugins/dird/python-dir.cc	2020-01-31 15:50:39.024455000 -0500
@@ -41,6 +41,13 @@
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
 
@@ -121,6 +128,20 @@
  */
 static PyThreadState* mainThreadState;
 
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
@@ -660,7 +681,11 @@
     /*
      * Make our callback methods available for Python.
      */
+#if (PY_VERSION_HEX >  0x03050000)
+    p_ctx->pInstance = PyModule_Create(&BareosDIRModuleDef);
+#else
     p_ctx->pInstance = Py_InitModule("bareosdir", BareosDIRMethods);
+#endif
   }
 
   /*
@@ -939,7 +964,11 @@
       char* value;
 
       ctx = PyGetbpContext(pyCtx);
+#if (PY_VERSION_HEX >  0x03050000)
+      value = strdup(PyString_AsString(pyValue));
+#else
       value = PyString_AsString(pyValue);
+#endif
       if (value) {
         retval = bfuncs->setBareosValue(ctx, (bwDirVariable)var, value);
       }
