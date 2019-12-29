--- src/plugins/stored/python-sd.c	2019-12-29 01:43:28.821366000 -0500
+++ src/plugins/stored/python-sd.c	2019-12-29 01:45:39.796709000 -0500
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
+static struct PyModuleDef BareosSDModuleDef = {
+  PyModuleDef_HEAD_INIT,
+  "bareossd",
+  NULL,
+  -1,
+  BareosSDMethods,
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
@@ -695,7 +716,11 @@
       /*
        * Make our callback methods available for Python.
        */
+#if (PY_VERSION_HEX >  0x03050000)
+      p_ctx->pInstance = PyModule_Create(&BareosSDModuleDef);
+#else
       p_ctx->pInstance = Py_InitModule("bareossd", BareosSDMethods);
+#endif
    }
 
    /*
@@ -976,7 +1001,11 @@
       char *value;
 
       ctx = PyGetbpContext(pyCtx);
+#if (PY_VERSION_HEX >  0x03050000)
+      value = bstrdup(PyString_AsString(pyValue));
+#else
       value = PyString_AsString(pyValue);
+#endif
       if (value) {
          bfuncs->setBareosValue(ctx, (bsdwVariable)var, value);
       }
