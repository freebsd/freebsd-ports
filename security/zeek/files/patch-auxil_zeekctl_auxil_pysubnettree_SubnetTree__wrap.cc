--- auxil/zeekctl/auxil/pysubnettree/SubnetTree_wrap.cc.orig	2024-05-16 17:25:57 UTC
+++ auxil/zeekctl/auxil/pysubnettree/SubnetTree_wrap.cc
@@ -1629,6 +1629,14 @@ SwigPyObject_repr(SwigPyObject *v, PyObject *args)
   return repr;  
 }
 
+/* We need a version taking two PyObject* parameters so it's a valid
+ * PyCFunction to use in swigobject_methods[]. */
+SWIGRUNTIME PyObject *
+SwigPyObject_repr2(PyObject *v, PyObject *SWIGUNUSEDPARM(args))
+{
+  return SwigPyObject_repr((SwigPyObject*)v);
+}
+
 SWIGRUNTIME int
 SwigPyObject_compare(SwigPyObject *v, SwigPyObject *w)
 {
@@ -1741,11 +1749,7 @@ SWIGRUNTIME PyObject* 
 }
 
 SWIGRUNTIME PyObject* 
-#ifdef METH_NOARGS
-SwigPyObject_next(PyObject* v)
-#else
 SwigPyObject_next(PyObject* v, PyObject *SWIGUNUSEDPARM(args))
-#endif
 {
   SwigPyObject *sobj = (SwigPyObject *) v;
   if (sobj->next) {    
@@ -1780,6 +1784,20 @@ SwigPyObject_acquire(PyObject* v, PyObject *SWIGUNUSED
   return SWIG_Py_Void();
 }
 
+#ifdef METH_NOARGS
+static PyObject*
+SwigPyObject_disown2(PyObject* v, PyObject *SWIGUNUSEDPARM(args))
+{
+  return SwigPyObject_disown(v);
+}
+
+static PyObject*
+SwigPyObject_acquire2(PyObject* v, PyObject *SWIGUNUSEDPARM(args))
+{
+  return SwigPyObject_acquire(v);
+}
+#endif
+
 SWIGINTERN PyObject*
 SwigPyObject_own(PyObject *v, PyObject *args)
 {
@@ -1820,12 +1838,12 @@ swigobject_methods[] = {
 #ifdef METH_O
 static PyMethodDef
 swigobject_methods[] = {
-  {(char *)"disown",  (PyCFunction)SwigPyObject_disown,  METH_NOARGS,  (char *)"releases ownership of the pointer"},
-  {(char *)"acquire", (PyCFunction)SwigPyObject_acquire, METH_NOARGS,  (char *)"acquires ownership of the pointer"},
+  {(char *)"disown",  (PyCFunction)SwigPyObject_disown2, METH_NOARGS,  (char *)"releases ownership of the pointer"},
+  {(char *)"acquire", (PyCFunction)SwigPyObject_acquire2,METH_NOARGS,  (char *)"acquires ownership of the pointer"},
   {(char *)"own",     (PyCFunction)SwigPyObject_own,     METH_VARARGS, (char *)"returns/sets ownership of the pointer"},
   {(char *)"append",  (PyCFunction)SwigPyObject_append,  METH_O,       (char *)"appends another 'this' object"},
   {(char *)"next",    (PyCFunction)SwigPyObject_next,    METH_NOARGS,  (char *)"returns the next 'this' object"},
-  {(char *)"__repr__",(PyCFunction)SwigPyObject_repr,    METH_NOARGS,  (char *)"returns object representation"},
+  {(char *)"__repr__",(PyCFunction)SwigPyObject_repr2,   METH_NOARGS,  (char *)"returns object representation"},
   {0, 0, 0, 0}  
 };
 #else
@@ -1836,7 +1854,7 @@ swigobject_methods[] = {
   {(char *)"own",     (PyCFunction)SwigPyObject_own,     METH_VARARGS,  (char *)"returns/sets ownership of the pointer"},
   {(char *)"append",  (PyCFunction)SwigPyObject_append,  METH_VARARGS,  (char *)"appends another 'this' object"},
   {(char *)"next",    (PyCFunction)SwigPyObject_next,    METH_VARARGS,  (char *)"returns the next 'this' object"},
-  {(char *)"__repr__",(PyCFunction)SwigPyObject_repr,   METH_VARARGS,  (char *)"returns object representation"},
+  {(char *)"__repr__",(PyCFunction)SwigPyObject_repr,    METH_VARARGS,  (char *)"returns object representation"},
   {0, 0, 0, 0}  
 };
 #endif
@@ -3457,7 +3475,7 @@ SWIGINTERN PyObject *SubnetTree___getitem__(SubnetTree
 
            PyObject* data = self->lookup(cidr, size);
            if ( ! data ) {
-               PyErr_SetString(PyExc_KeyError, cidr);
+	       PyErr_SetObject(PyExc_KeyError, PyBytes_FromStringAndSize(cidr, size));
                return 0;
            }
 
@@ -4814,27 +4832,27 @@ static PyMethodDef SwigMethods[] = {
 }
 
 static PyMethodDef SwigMethods[] = {
-	 { (char *)"SWIG_PyInstanceMethod_New", (PyCFunction)SWIG_PyInstanceMethod_New, METH_O, NULL},
-	 { (char *)"inx_addr_sin_set", _wrap_inx_addr_sin_set, METH_VARARGS, NULL},
-	 { (char *)"inx_addr_sin_get", _wrap_inx_addr_sin_get, METH_VARARGS, NULL},
-	 { (char *)"inx_addr_sin6_set", _wrap_inx_addr_sin6_set, METH_VARARGS, NULL},
-	 { (char *)"inx_addr_sin6_get", _wrap_inx_addr_sin6_get, METH_VARARGS, NULL},
-	 { (char *)"new_inx_addr", _wrap_new_inx_addr, METH_VARARGS, NULL},
-	 { (char *)"delete_inx_addr", _wrap_delete_inx_addr, METH_VARARGS, NULL},
-	 { (char *)"inx_addr_swigregister", inx_addr_swigregister, METH_VARARGS, NULL},
-	 { (char *)"new_SubnetTree", _wrap_new_SubnetTree, METH_VARARGS, NULL},
-	 { (char *)"delete_SubnetTree", _wrap_delete_SubnetTree, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_insert", _wrap_SubnetTree_insert, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_remove", _wrap_SubnetTree_remove, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_lookup", _wrap_SubnetTree_lookup, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_prefixes", _wrap_SubnetTree_prefixes, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_get_binary_lookup_mode", _wrap_SubnetTree_get_binary_lookup_mode, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_set_binary_lookup_mode", _wrap_SubnetTree_set_binary_lookup_mode, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree___contains__", _wrap_SubnetTree___contains__, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree___getitem__", _wrap_SubnetTree___getitem__, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree___setitem__", _wrap_SubnetTree___setitem__, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree___delitem__", _wrap_SubnetTree___delitem__, METH_VARARGS, NULL},
-	 { (char *)"SubnetTree_swigregister", SubnetTree_swigregister, METH_VARARGS, NULL},
+	 { "SWIG_PyInstanceMethod_New", SWIG_PyInstanceMethod_New, METH_O, NULL},
+	 { "inx_addr_sin_set", _wrap_inx_addr_sin_set, METH_VARARGS, NULL},
+	 { "inx_addr_sin_get", _wrap_inx_addr_sin_get, METH_VARARGS, NULL},
+	 { "inx_addr_sin6_set", _wrap_inx_addr_sin6_set, METH_VARARGS, NULL},
+	 { "inx_addr_sin6_get", _wrap_inx_addr_sin6_get, METH_VARARGS, NULL},
+	 { "new_inx_addr", _wrap_new_inx_addr, METH_VARARGS, NULL},
+	 { "delete_inx_addr", _wrap_delete_inx_addr, METH_VARARGS, NULL},
+	 { "inx_addr_swigregister", inx_addr_swigregister, METH_VARARGS, NULL},
+	 { "new_SubnetTree", _wrap_new_SubnetTree, METH_VARARGS, NULL},
+	 { "delete_SubnetTree", _wrap_delete_SubnetTree, METH_VARARGS, NULL},
+	 { "SubnetTree_insert", _wrap_SubnetTree_insert, METH_VARARGS, NULL},
+	 { "SubnetTree_remove", _wrap_SubnetTree_remove, METH_VARARGS, NULL},
+	 { "SubnetTree_lookup", _wrap_SubnetTree_lookup, METH_VARARGS, NULL},
+	 { "SubnetTree_prefixes", _wrap_SubnetTree_prefixes, METH_VARARGS, NULL},
+	 { "SubnetTree_get_binary_lookup_mode", _wrap_SubnetTree_get_binary_lookup_mode, METH_VARARGS, NULL},
+	 { "SubnetTree_set_binary_lookup_mode", _wrap_SubnetTree_set_binary_lookup_mode, METH_VARARGS, NULL},
+	 { "SubnetTree___contains__", _wrap_SubnetTree___contains__, METH_VARARGS, NULL},
+	 { "SubnetTree___getitem__", _wrap_SubnetTree___getitem__, METH_VARARGS, NULL},
+	 { "SubnetTree___setitem__", _wrap_SubnetTree___setitem__, METH_VARARGS, NULL},
+	 { "SubnetTree___delitem__", _wrap_SubnetTree___delitem__, METH_VARARGS, NULL},
+	 { "SubnetTree_swigregister", SubnetTree_swigregister, METH_VARARGS, NULL},
 	 { NULL, NULL, 0, NULL }
 };
 
@@ -5399,9 +5417,9 @@ extern "C" {
             char *ndoc = (char*)malloc(ldoc + lptr + 10);
             if (ndoc) {
               char *buff = ndoc;
-              strncpy(buff, methods[i].ml_doc, ldoc);
+              memcpy(buff, methods[i].ml_doc, ldoc);
               buff += ldoc;
-              strncpy(buff, "swig_ptr: ", 10);
+              memcpy(buff, "swig_ptr: ", 10);
               buff += 10;
               SWIG_PackVoidPtr(buff, ptr, ty->name, lptr);
               methods[i].ml_doc = ndoc;
@@ -5463,8 +5481,8 @@ SWIG_init(void) {
     (char *)"this", &SwigPyBuiltin_ThisClosure, NULL, NULL, NULL
   };
   static SwigPyGetSet thisown_getset_closure = {
-    (PyCFunction) SwigPyObject_own,
-    (PyCFunction) SwigPyObject_own
+    SwigPyObject_own,
+    SwigPyObject_own
   };
   static PyGetSetDef thisown_getset_def = {
     (char *)"thisown", SwigPyBuiltin_GetterClosure, SwigPyBuiltin_SetterClosure, NULL, &thisown_getset_closure
