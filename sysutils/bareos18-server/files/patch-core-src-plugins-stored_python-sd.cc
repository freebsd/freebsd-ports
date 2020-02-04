--- core/src/plugins/stored/python-sd.cc	2019-12-12 12:04:14.000000000 -0500
+++ core/src/plugins/stored/python-sd.cc	2019-12-29 00:19:19.366390000 -0500
@@ -36,6 +36,13 @@
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
 
 #define PLUGIN_LICENSE      "Bareos AGPLv3"
@@ -121,6 +128,20 @@
 extern "C" {
 #endif
 
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
 /**
  * loadPlugin() and unloadPlugin() are entry points that are
  *  exported, so Bareos can directly call these two entry points
@@ -698,7 +719,11 @@
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
@@ -979,7 +1004,11 @@
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
