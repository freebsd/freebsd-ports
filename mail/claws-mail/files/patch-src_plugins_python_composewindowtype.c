--- src/plugins/python/composewindowtype.c.orig	2019-01-09 18:38:06 UTC
+++ src/plugins/python/composewindowtype.c
@@ -54,7 +54,7 @@ static void ComposeWindow_dealloc(clawsm
   Py_XDECREF(self->text);
   Py_XDECREF(self->replyinfo);
   Py_XDECREF(self->fwdinfo);
-  self->ob_type->tp_free((PyObject*)self);
+  Py_TYPE(self)->tp_free((PyObject*)self);
 }
 
 static void flush_gtk_queue(void)
@@ -345,7 +345,7 @@ static PyObject* ComposeWindow_set_heade
     headerfield = PyTuple_GetItem(element, 0);
     headercontent = PyTuple_GetItem(element, 1);
     if(!headerfield || !headercontent
-        || !PyObject_TypeCheck(headerfield, &PyString_Type) || !PyObject_TypeCheck(headercontent, &PyString_Type)) {
+        || !PyObject_TypeCheck(headerfield, &PyBytes_Type) || !PyObject_TypeCheck(headercontent, &PyBytes_Type)) {
       PyErr_SetString(PyExc_LookupError, "Argument to set_header_list() must be a list of tuples with two strings");
       return NULL;
     }
