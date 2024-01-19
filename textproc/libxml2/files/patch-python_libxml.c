--- python/libxml.c.orig	2023-08-11 20:30:35 UTC
+++ python/libxml.c
@@ -1606,12 +1606,19 @@ libxml_xmlErrorFuncHandler(ATTRIBUTE_UNUSED void *ctx,
     PyObject *message;
     PyObject *result;
     char str[1000];
+    unsigned char *ptr = (unsigned char *)str;
 
 #ifdef DEBUG_ERROR
     printf("libxml_xmlErrorFuncHandler(%p, %s, ...) called\n", ctx, msg);
 #endif
 
+#if PY_MAJOR_VERSION >= 3
+    /* Ensure the error string doesn't start at UTF8 continuation. */
+    while (*ptr && (*ptr & 0xc0) == 0x80)
+        ptr++;
+#endif
 
+
     if (libxml_xmlPythonErrorFuncHandler == NULL) {
         va_start(ap, msg);
         vfprintf(stderr, msg, ap);
@@ -1625,9 +1632,11 @@ libxml_xmlErrorFuncHandler(ATTRIBUTE_UNUSED void *ctx,
         list = PyTuple_New(2);
         PyTuple_SetItem(list, 0, libxml_xmlPythonErrorFuncCtxt);
         Py_XINCREF(libxml_xmlPythonErrorFuncCtxt);
-        message = libxml_charPtrConstWrap(str);
+        message = libxml_charPtrConstWrap(ptr);
         PyTuple_SetItem(list, 1, message);
         result = PyObject_CallObject(libxml_xmlPythonErrorFuncHandler, list);
+        /* Forget any errors caused in the error handler. */
+        PyErr_Clear();
         Py_XDECREF(list);
         Py_XDECREF(result);
     }
