--- miltermodule.c.orig	2016-12-13 19:17:34 UTC
+++ miltermodule.c
@@ -343,7 +343,7 @@ static struct MilterCallback {
       { NULL , NULL }
     };
 
-staticforward struct smfiDesc description; /* forward declaration */
+static struct smfiDesc description; /* forward declaration */
 
 static PyObject *MilterError;
 /* The interpreter instance that called milter.main */
@@ -355,7 +355,7 @@ typedef struct {
 
 static milter_Diag diag;
 
-staticforward PyTypeObject milter_ContextType;
+static PyTypeObject milter_ContextType;
 
 typedef struct {
   PyObject_HEAD
@@ -700,7 +700,7 @@ _generic_wrapper(milter_ContextObject *s
   result = PyEval_CallObject(cb, arglist);
   Py_DECREF(arglist);
   if (result == NULL) return _report_exception(self);
-  if (!PyInt_Check(result)) {
+  if (!PyLong_Check(result)) {
     const struct MilterCallback *p;
     const char *cbname = "milter";
     char buf[40];
@@ -715,7 +715,7 @@ _generic_wrapper(milter_ContextObject *s
     PyErr_SetString(MilterError,buf);
     return _report_exception(self);
   }
-  retval = PyInt_AS_LONG(result);
+  retval = PyLong_AS_LONG(result);
   Py_DECREF(result);
   _release_thread(self->t);
   return retval;
@@ -732,7 +732,7 @@ makeipaddr(struct sockaddr_in *addr) {
 	sprintf(buf, "%d.%d.%d.%d",
 		(int) (x>>24) & 0xff, (int) (x>>16) & 0xff,
 		(int) (x>> 8) & 0xff, (int) (x>> 0) & 0xff);
-	return PyString_FromString(buf);
+	return PyUnicode_FromString(buf);
 }
 
 #ifdef HAVE_IPV6_SUPPORT
@@ -740,8 +740,8 @@ static PyObject *
 makeip6addr(struct sockaddr_in6 *addr) {
 	char buf[100]; /* must be at least INET6_ADDRSTRLEN + 1 */
 	const char *s = inet_ntop(AF_INET6, &addr->sin6_addr, buf, sizeof buf);
-	if (s) return PyString_FromString(s);
-	return PyString_FromString("inet6:unknown");
+	if (s) return PyUnicode_FromString(s);
+	return PyUnicode_FromString("inet6:unknown");
 }
 #endif
 
@@ -832,7 +832,7 @@ generic_env_wrapper(SMFICTX *ctx, PyObje
    for (i=0;i<count;i++) {
      /* There's some error checking performed in do_mkvalue() for a string */
      /* that's not currently done here - it probably should be */
-     PyObject *o = PyString_FromStringAndSize(argv[i], strlen(argv[i]));
+     PyObject *o = PyUnicode_FromStringAndSize(argv[i], strlen(argv[i]));
      if (o == NULL) {	/* out of memory */
        Py_DECREF(arglist);
        return _report_exception(self);
@@ -889,7 +889,7 @@ milter_wrap_body(SMFICTX *ctx, u_char *b
    c = _get_context(ctx);
    if (!c) return SMFIS_TEMPFAIL;
    /* Unclear whether this should be s#, z#, or t# */
-   arglist = Py_BuildValue("(Os#)", c, bodyp, bodylen);
+   arglist = Py_BuildValue("(Oy#)", c, bodyp, bodylen);
    return _generic_wrapper(c, body_callback, arglist);
 }
 
@@ -963,7 +963,7 @@ milter_wrap_negotiate(SMFICTX *ctx,
     int i;
     for (i = 0; i < 4; ++i) {
       *pa[i] = (i <= len)
-      	? PyInt_AsUnsignedLongMask(PyList_GET_ITEM(optlist,i))
+      	? PyLong_AsUnsignedLongMask(PyList_GET_ITEM(optlist,i))
 	: fa[i];
     }
     if (PyErr_Occurred()) {
@@ -1551,11 +1551,6 @@ static PyMethodDef context_methods[] = {
   { NULL, NULL }
 };
 
-static PyObject *
-milter_Context_getattr(PyObject *self, char *name) {
-  return Py_FindMethod(context_methods, self, name);
-}
-
 static struct smfiDesc description = {  /* Set some reasonable defaults */
   "pythonfilter",
   SMFI_VERSION,
@@ -1604,14 +1599,13 @@ static PyMethodDef milter_methods[] = {
 };
 
 static PyTypeObject milter_ContextType = {
-  PyObject_HEAD_INIT(&PyType_Type)
-  0,
-  "milterContext",
+  PyVarObject_HEAD_INIT(&PyType_Type,0)
+  "milter.Context",
   sizeof(milter_ContextObject),
   0,
         milter_Context_dealloc,            /* tp_dealloc */
         0,               /* tp_print */
-        milter_Context_getattr,           /* tp_getattr */
+        0,           /* tp_getattr */
         0,			/* tp_setattr */
         0,                                      /* tp_compare */
         0,                 /* tp_repr */
@@ -1625,6 +1619,13 @@ static PyTypeObject milter_ContextType =
         0,                                      /* tp_setattro */
         0,                                      /* tp_as_buffer */
         Py_TPFLAGS_DEFAULT,                     /* tp_flags */
+	NULL,	/* Documentation string */
+	0, 	/* call function for all accessible objects */
+    	0,	/* delete references to contained objects */
+    	0,	/* rich comparisons */
+    	0,	/* weak reference enabler */
+    	0, 0,	/* Iterators */
+    	context_methods, /* Attribute descriptor and subclassing stuff */
 };
 
 static const char milter_documentation[] =
@@ -1634,17 +1635,31 @@ Libmilter is currently marked FFR, and n
 See <sendmailsource>/libmilter/README for details on setting it up.\n";
 
 static void setitem(PyObject *d,const char *name,long val) {
-  PyObject *v = PyInt_FromLong(val);
+  PyObject *v = PyLong_FromLong(val);
   PyDict_SetItemString(d,name,v);
   Py_DECREF(v);
 }
 
-void
-initmilter(void) {
+static struct PyModuleDef moduledef = {
+    PyModuleDef_HEAD_INIT,
+    "milter",     	 /* m_name */
+    milter_documentation,/* m_doc */
+    -1,                  /* m_size */
+    milter_methods,      /* m_methods */
+    NULL,                /* m_reload */
+    NULL,                /* m_traverse */
+    NULL,                /* m_clear */
+    NULL,                /* m_free */
+};
+
+PyMODINIT_FUNC PyInit_milter(void) {
    PyObject *m, *d;
 
-   m = Py_InitModule4("milter", milter_methods, milter_documentation,
-		      (PyObject*)NULL, PYTHON_API_VERSION);
+   if (PyType_Ready(&milter_ContextType) < 0)
+          return NULL;
+
+   m = PyModule_Create(&moduledef);
+   if (m == NULL) return NULL;
    d = PyModule_GetDict(m);
    MilterError = PyErr_NewException("milter.error", NULL, NULL);
    PyDict_SetItemString(d,"error", MilterError);
@@ -1710,4 +1725,5 @@ initmilter(void) {
    setitem(d,"DISCARD",  SMFIS_DISCARD);
    setitem(d,"ACCEPT",  SMFIS_ACCEPT);
    setitem(d,"TEMPFAIL",  SMFIS_TEMPFAIL);
+   return m;
 }
