--- PAMmodule.c.orig	2026-05-24 01:06:49 UTC
+++ PAMmodule.c
@@ -10,7 +10,7 @@
 
 #include <Python.h>
 #include <security/pam_appl.h>
-#include <security/pam_misc.h>
+#include <security/openpam.h>
 
 static PyObject *PyPAM_Error;
 
@@ -24,7 +24,7 @@ typedef struct {
     PyObject            *userData;
 } PyPAMObject;
 
-staticforward PyTypeObject PyPAMObject_Type;
+static PyTypeObject PyPAMObject_Type;
 
 static void PyPAM_Err(PyPAMObject *self, int result)
 {
@@ -60,7 +60,7 @@ static int PyPAM_conv(int num_msg, const struct pam_me
     }
     
     args = Py_BuildValue("(OOO)", self, msgList, self->userData);
-    respList = PyEval_CallObject(self->callback, args);
+    respList = PyObject_CallObject(self->callback, args);
     Py_DECREF(args);
     Py_DECREF(self);
     
@@ -80,6 +80,7 @@ static int PyPAM_conv(int num_msg, const struct pam_me
         resp_retcode = 0;
         if (!PyArg_ParseTuple(respTuple, "si", &resp_text, &resp_retcode)) {
             free(*resp);
+            *resp = NULL;
             Py_DECREF(respList);
             return PAM_CONV_ERR;
         }
@@ -92,7 +93,7 @@ static struct pam_conv default_conv = {
 }
 
 static struct pam_conv default_conv = {
-    misc_conv,
+    openpam_ttyconv,
     NULL
 };
 
@@ -101,12 +102,18 @@ static struct pam_conv python_conv = {
     NULL
 };
 
+#if PY_VERSION_HEX < 0x030900A4 && !defined(Py_SET_TYPE)
+static inline void _Py_SET_TYPE(PyObject *ob, PyTypeObject *type)
+{ ob->ob_type = type; }
+#define Py_SET_TYPE(ob, type) _Py_SET_TYPE((PyObject*)(ob), type)
+#endif
+
 static PyObject * PyPAM_pam(PyObject *self, PyObject *args)
 {
     PyPAMObject         *p;
     struct pam_conv     *spc;
 
-    PyPAMObject_Type.ob_type = &PyType_Type;
+    Py_SET_TYPE(&PyPAMObject_Type, &PyType_Type);
     p = (PyPAMObject *) PyObject_NEW(PyPAMObject, &PyPAMObject_Type);
 
     if ((spc = (struct pam_conv *) malloc(sizeof(struct pam_conv))) == NULL) {
@@ -313,7 +320,7 @@ static PyObject * PyPAM_set_item(PyObject *self, PyObj
         if (item == PAM_SERVICE) _self->service = n_val;
         result = pam_set_item(_self->pamh, item, (void *) n_val);
     } else {
-		PyErr_Clear();
+        PyErr_Clear();
         if (PyArg_ParseTuple(args, "iO:set_callback", &item, &o_val)) {
             if (item == PAM_CONV && !PyCallable_Check(o_val)) {
                 PyErr_SetString(PyExc_TypeError, "parameter must be a function");
@@ -489,35 +496,33 @@ static void PyPAM_dealloc(PyPAMObject *self)
     PyObject_FREE(self);
 }
 
-static PyObject * PyPAM_getattr(PyPAMObject *self, char *name)
-{
-    return Py_FindMethod(PyPAMObject_Methods, (PyObject *) self, name);
-}
-
 static PyObject * PyPAM_repr(PyPAMObject *self)
 {
     char                buf[1024];
     
     snprintf(buf, 1024, "<pam object, service=\"%s\", user=\"%s\", conv=%p, pamh=%p>",
         self->service, self->user, self->conv, self->pamh);
-    return PyString_FromString(buf);
+    return PyUnicode_FromString(buf);
 }
 
 static PyTypeObject PyPAMObject_Type = {
-    PyObject_HEAD_INIT(0)   /* Must fill in type value later */
-    0,
+    PyVarObject_HEAD_INIT(&PyType_Type, 0)   /* Must fill in type value later */
     "pam",
     sizeof(PyPAMObject),
     0,
     (destructor)PyPAM_dealloc,      /*tp_dealloc*/
     0,      /*tp_print*/
-    (getattrfunc)PyPAM_getattr,     /*tp_getattr*/
+    0,      /*tp_getattr*/
     0,      /*tp_setattr*/
     0,      /*tp_compare*/
     (reprfunc)PyPAM_repr,           /*tp_repr*/
     0,      /*tp_as_number*/
     0,      /*tp_as_sequence*/
     0,      /*tp_as_mapping*/
+    0,      /*hash*/
+    0,      /*ternary*/
+    0,      /*another repr*/
+    (getattrofunc)PyObject_GenericGetAttr,
 };
 
 static PyMethodDef PyPAM_Methods[] = {
@@ -525,6 +530,16 @@ static PyMethodDef PyPAM_Methods[] = {
     {NULL, NULL, 0, NULL}
 };
 
+#if PY_MAJOR_VERSION > 2
+static struct PyModuleDef PyPAM_Module = {
+    PyModuleDef_HEAD_INIT,
+    "PAM",    /* name of module */
+    NULL,     /* module documentation */
+    -1,       /* size of per-interpreter state */
+    PyPAM_Methods
+};
+#endif
+
 static char PyPAMObject_doc[] = "";
 
 /* Convenience routine to export an integer value.
@@ -534,7 +549,11 @@ static void insint(PyObject *d, char *name, int value)
  */
 static void insint(PyObject *d, char *name, int value)
 {
+#if PY_MAJOR_VERSION > 2
+    PyObject            *v = PyLong_FromLong((long) value);
+#else
     PyObject            *v = PyInt_FromLong((long) value);
+#endif
 
     if (!v || PyDict_SetItemString(d, name, v))
         PyErr_Clear();
@@ -542,20 +561,32 @@ static void insint(PyObject *d, char *name, int value)
     Py_XDECREF(v);
 }
 
+#if PY_MAJOR_VERSION > 2
+PyMODINIT_FUNC PyInit_PAM(void)
+#else
 void initPAM(void)
+#endif
 {
     PyObject            *m, *d;
 
+#if PY_MAJOR_VERSION > 2
+    m = PyModule_Create(&PyPAM_Module);
+#else
     m = Py_InitModule("PAM", PyPAM_Methods);
+#endif
     d = PyModule_GetDict(m);
     
     PyPAM_Error = PyErr_NewException("PAM.error", NULL, NULL);
     if (PyPAM_Error == NULL)
+#if PY_MAJOR_VERSION > 2
+        return m;
+#else
         return;
+#endif
     PyDict_SetItemString(d, "error", PyPAM_Error);
 
-    PyPAMObject_Type.ob_type = &PyType_Type;
     PyPAMObject_Type.tp_doc = PyPAMObject_doc;
+    PyPAMObject_Type.tp_methods = PyPAMObject_Methods,
     Py_INCREF(&PyPAMObject_Type);
 
     insint(d, "PAM_SUCCESS", PAM_SUCCESS);
@@ -579,7 +610,7 @@ void initPAM(void)
     insint(d, "PAM_NO_MODULE_DATA", PAM_NO_MODULE_DATA);
     insint(d, "PAM_CONV_ERR", PAM_CONV_ERR);
     insint(d, "PAM_AUTHTOK_ERR", PAM_AUTHTOK_ERR);
-    insint(d, "PAM_AUTHTOK_RECOVER_ERR", PAM_AUTHTOK_RECOVER_ERR);
+    insint(d, "PAM_AUTHTOK_RECOVER_ERR", PAM_AUTHTOK_RECOVERY_ERR);
     insint(d, "PAM_AUTHTOK_LOCK_BUSY", PAM_AUTHTOK_LOCK_BUSY);
     insint(d, "PAM_AUTHTOK_DISABLE_AGING", PAM_AUTHTOK_DISABLE_AGING);
     insint(d, "PAM_TRY_AGAIN", PAM_TRY_AGAIN);
@@ -588,7 +619,7 @@ void initPAM(void)
     insint(d, "PAM_AUTHTOK_EXPIRED", PAM_AUTHTOK_EXPIRED);
     insint(d, "PAM_MODULE_UNKNOWN", PAM_MODULE_UNKNOWN);
     insint(d, "PAM_BAD_ITEM", PAM_BAD_ITEM);
-    insint(d, "_PAM_RETURN_VALUES", _PAM_RETURN_VALUES);
+    insint(d, "_PAM_RETURN_VALUES", PAM_NUM_ERRORS);
 
     insint(d, "PAM_SILENT", PAM_SILENT);
     insint(d, "PAM_DISALLOW_NULL_AUTHTOK", PAM_DISALLOW_NULL_AUTHTOK);
@@ -607,7 +638,7 @@ void initPAM(void)
     insint(d, "PAM_RUSER", PAM_RUSER);
     insint(d, "PAM_USER_PROMPT", PAM_USER_PROMPT);
 
-    insint(d, "PAM_DATA_SILENT", PAM_DATA_SILENT);
+    insint(d, "PAM_DATA_SILENT", 0);
 
     insint(d, "PAM_PROMPT_ECHO_OFF", PAM_PROMPT_ECHO_OFF);
     insint(d, "PAM_PROMPT_ECHO_ON", PAM_PROMPT_ECHO_ON);
@@ -617,6 +648,10 @@ void initPAM(void)
     insint(d, "PAM_RADIO_TYPE", PAM_RADIO_TYPE);
     insint(d, "PAM_BINARY_MSG", PAM_BINARY_MSG);
     insint(d, "PAM_BINARY_PROMPT", PAM_BINARY_PROMPT);
+#endif
+
+#if PY_MAJOR_VERSION > 2
+    return m;
 #endif
 
 }
