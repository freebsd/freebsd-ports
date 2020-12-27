--- core/src/plugins/stored/python-sd.cc	2020-01-31 11:21:18.000000000 -0500
+++ core/src/plugins/stored/python-sd.cc	2020-01-31 16:07:55.684864000 -0500
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
 static const int debuglevel = 150;
 
 #define PLUGIN_LICENSE "Bareos AGPLv3"
@@ -119,6 +126,20 @@
  */
 static PyThreadState* mainThreadState;
 
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
@@ -678,7 +699,11 @@
     /*
      * Make our callback methods available for Python.
      */
+#if (PY_VERSION_HEX >  0x03050000)
+    p_ctx->pInstance = PyModule_Create(&BareosSDModuleDef);
+#else
     p_ctx->pInstance = Py_InitModule("bareossd", BareosSDMethods);
+#endif
   }
 
   /*
@@ -958,7 +983,11 @@
       char* value;
 
       ctx = PyGetbpContext(pyCtx);
+#if (PY_VERSION_HEX >  0x03050000)
+      value = strdup(PyString_AsString(pyValue));
+#else
       value = PyString_AsString(pyValue);
+#endif
       if (value) { bfuncs->setBareosValue(ctx, (bsdwVariable)var, value); }
 
       break;
