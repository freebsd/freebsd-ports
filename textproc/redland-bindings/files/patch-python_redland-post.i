--- python/redland-post.i.orig	2014-01-07 02:39:02 UTC
+++ python/redland-post.i
@@ -111,7 +111,7 @@ librdf_call_python_message(int code, int level, int fa
     fprintf(stderr, "librdf_call_python_message: Out of memory\n");
     return 0;
   }
-  result = PyEval_CallObject(librdf_python_callback, arglist);
+  result = (PyObject *)PyEval_CallObject(librdf_python_callback, arglist);
   Py_DECREF(arglist);
   if(result) {
     if(PyInt_Check(result))
@@ -201,7 +201,7 @@ librdf_call_python_uri_filter(void* user_data, librdf_
     fprintf(stderr, "librdf_call_python_uri_filter: Out of memory\n");
     return 0;
   }
-  result = PyEval_CallObject(callback, arglist);
+  result = (PyObject *)PyEval_CallObject(callback, arglist);
   Py_DECREF(arglist);
   if(result) {
     if(PyInt_Check(result))
