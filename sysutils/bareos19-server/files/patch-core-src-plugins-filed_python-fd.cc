--- core/src/plugins/filed/python-fd.cc	2020-01-31 11:21:18.000000000 -0500
+++ core/src/plugins/filed/python-fd.cc	2020-01-31 17:58:06.370789000 -0500
@@ -46,6 +46,14 @@
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
 static const int debuglevel = 150;
 
 #define PLUGIN_LICENSE "Bareos AGPLv3"
@@ -154,6 +162,20 @@
  */
 static PyThreadState* mainThreadState;
 
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
@@ -1148,7 +1170,11 @@
     /*
      * Make our callback methods available for Python.
      */
+#if (PY_VERSION_HEX >  0x03050000)
+    p_ctx->pInstance = PyModule_Create(&BareosFDModuleDef);
+#else
     p_ctx->pInstance = Py_InitModule("bareosfd", BareosFDMethods);
+#endif
 
     /*
      * Fill in the slots of PyRestoreObject
@@ -2587,7 +2613,11 @@
     case bVarFileSeen: {
       char* value;
 
+#if (PY_VERSION_HEX >  0x03050000)
+      value = strdup(PyString_AsString(pyValue));
+#else
       value = PyString_AsString(pyValue);
+#endif
       if (value) {
         retval = bfuncs->setBareosValue(ctx, (bVariable)var, value);
       }
@@ -2972,7 +3002,11 @@
   sp.type = pSavePkt->type;
   if (pSavePkt->fname) {
     if (PyString_Check(pSavePkt->fname)) {
+#if (PY_VERSION_HEX >  0x03050000)
+      sp.fname = strdup(PyString_AsString(pSavePkt->fname));
+#else
       sp.fname = PyString_AsString(pSavePkt->fname);
+#endif
     } else {
       goto bail_out;
     }
@@ -2981,7 +3015,11 @@
   }
   if (pSavePkt->link) {
     if (PyString_Check(pSavePkt->link)) {
+#if (PY_VERSION_HEX >  0x03050000)
+      sp.link = strdup(PyString_AsString(pSavePkt->link));
+#else
       sp.link = PyString_AsString(pSavePkt->link);
+#endif
     } else {
       goto bail_out;
     }
@@ -3025,7 +3063,11 @@
    */
   if (pSavePkt->fname) {
     if (PyString_Check(pSavePkt->fname)) {
+#if (PY_VERSION_HEX >  0x03050000)
+      sp.fname = strdup(PyString_AsString(pSavePkt->fname));
+#else
       sp.fname = PyString_AsString(pSavePkt->fname);
+#endif
     } else {
       goto bail_out;
     }
@@ -3101,8 +3143,11 @@
 static inline char* PyGetStringValue(PyObject* object)
 {
   if (!object || !PyString_Check(object)) { return (char*)""; }
-
+#if (PY_VERSION_HEX >  0x03050000)
+  return strdup(PyString_AsString(object));
+#else
   return PyString_AsString(object);
+#endif
 }
 
 static inline char* PyGetByteArrayValue(PyObject* object)
