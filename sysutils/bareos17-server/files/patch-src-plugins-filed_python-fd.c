--- src/plugins/filed/python-fd.c	2019-12-29 01:20:40.033054000 -0500
+++ src/plugins/filed/python-fd.c	2019-12-29 01:27:28.921617000 -0500
@@ -37,6 +37,14 @@
 #error "Need at least Python version 2.6 or newer"
 #endif
 
+#if (PY_VERSION_HEX >  0x03050000)
+#define PyInt_AsLong PyLong_AsLong
+#define PyInt_FromLong PyLong_FromLong
+#define PyString_AsString PyUnicode_AsUTF8
+#define PyString_FromString PyUnicode_FromString
+#define PyString_Check PyBytes_Check
+#endif
+
 static const int dbglvl = 150;
 
 #define PLUGIN_LICENSE      "Bareos AGPLv3"
@@ -162,6 +170,20 @@
  */
 static PyThreadState *mainThreadState;
 
+#if (PY_VERSION_HEX >  0x03050000)
+static struct PyModuleDef BareosFDModuleDef = {
+  PyModuleDef_HEAD_INIT,
+  "bareosfd",
+  NULL,
+  -1,
+  BareosFDMethods,
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
@@ -1225,7 +1247,11 @@
       /*
        * Make our callback methods available for Python.
        */
+#if (PY_VERSION_HEX >  0x03050000)
+      p_ctx->pInstance = PyModule_Create(&BareosFDModuleDef);
+#else
       p_ctx->pInstance = Py_InitModule("bareosfd", BareosFDMethods);
+#endif
 
       /*
        * Fill in the slots of PyRestoreObject
@@ -2702,8 +2728,11 @@
    }
    case bVarFileSeen: {
       char *value;
-
+#if (PY_VERSION_HEX >  0x03050000)
+      value = bstrdup(PyString_AsString(pyValue));
+#else
       value = PyString_AsString(pyValue);
+#endif
       if (value) {
          retval = bfuncs->setBareosValue(ctx, (bVariable)var, value);
       }
@@ -3090,7 +3119,11 @@
    sp.type = pSavePkt->type;
    if (pSavePkt->fname) {
       if (PyString_Check(pSavePkt->fname)) {
+#if (PY_VERSION_HEX >  0x03050000)
+         sp.fname = bstrdup(PyString_AsString(pSavePkt->fname));
+#else
          sp.fname = PyString_AsString(pSavePkt->fname);
+#endif
       } else {
          goto bail_out;
       }
@@ -3099,7 +3132,11 @@
    }
    if (pSavePkt->link) {
       if (PyString_Check(pSavePkt->link)) {
+#if (PY_VERSION_HEX >  0x03050000)
+         sp.link = bstrdup(PyString_AsString(pSavePkt->link));
+#else
          sp.link = PyString_AsString(pSavePkt->link);
+#endif
       } else {
          goto bail_out;
       }
@@ -3142,7 +3179,11 @@
     */
    if (pSavePkt->fname) {
       if (PyString_Check(pSavePkt->fname)) {
+#if (PY_VERSION_HEX >  0x03050000)
+         sp.fname = bstrdup(PyString_AsString(pSavePkt->fname));
+#else
          sp.fname = PyString_AsString(pSavePkt->fname);
+#endif
       } else {
          goto bail_out;
       }
@@ -3219,7 +3260,11 @@
       return (char *)"";
    }
 
+#if (PY_VERSION_HEX >  0x03050000)
+   return bstrdup(PyString_AsString(object));
+#else
    return PyString_AsString(object);
+#endif
 }
 
 static inline char *PyGetByteArrayValue(PyObject *object)
