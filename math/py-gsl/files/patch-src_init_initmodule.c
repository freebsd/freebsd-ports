
$FreeBSD$

--- src/init/initmodule.c.orig
+++ src/init/initmodule.c
@@ -83,7 +83,7 @@
 
      FUNC_MESS_BEGIN();
 #if DEBUG == 1
-     PyObject *o;
+     { PyObject *o;
      int tmp, i, max, *ptr;
      if(!PyArg_ParseTuple(args, "i", &tmp))
 	  return NULL;
@@ -108,6 +108,7 @@
      Py_INCREF(Py_None);
      FUNC_MESS_END();
      return Py_None;
+     }
 #else 
      GSL_ERROR_NULL("PyGSL was not compiled with DEBUG = 1; Can not set DEBUG level!", GSL_EUNIMPL);
 #endif 
