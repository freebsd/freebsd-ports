--- src/init/initmodule.c.orig	2015-09-27 12:30:47 UTC
+++ src/init/initmodule.c
@@ -111,7 +111,7 @@ PyGSL_set_debug_level(PyObject *self, Py
 
      FUNC_MESS_BEGIN();
 #if DEBUG == 1
-     PyObject *o;
+     { PyObject *o;
      int tmp, i, max, *ptr;
      if(!PyArg_ParseTuple(args, "i", &tmp))
 	  return NULL;
@@ -136,6 +136,7 @@ PyGSL_set_debug_level(PyObject *self, Py
      Py_INCREF(Py_None);
      FUNC_MESS_END();
      return Py_None;
+     }
 #else 
      PyGSL_ERROR_NULL("PyGSL was not compiled with DEBUG = 1; Can not set DEBUG level!", GSL_EUNIMPL);
 #endif 
