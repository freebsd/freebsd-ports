--- src/plugins/dird/python-dir.c	2019-12-29 01:43:39.125609000 -0500
+++ src/plugins/dird/python-dir.c	2019-12-29 01:48:30.581353000 -0500
@@ -34,6 +34,13 @@
 #error "Need at least Python version 2.6 or newer"
 #endif
 
+#if (PY_VERSION_HEX >  0x03050000)
+#define PyInt_AsLong PyLong_AsLong
+#define PyInt_FromLong PyLong_FromLong
+#define PyString_AsString PyUnicode_AsUTF8
+#define PyString_FromString PyUnicode_FromString
+#endif
+
 static const int dbglvl = 150;
 
 #define PLUGIN_LICENSE      "Bareos AGPLv3"
@@ -114,6 +121,20 @@
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
@@ -675,7 +696,11 @@
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
@@ -955,7 +980,11 @@
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
