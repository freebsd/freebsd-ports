--- src/annoymodule.cc.orig	2023-01-12 04:57:07 UTC
+++ src/annoymodule.cc
@@ -179,7 +179,7 @@ py_an_init(py_annoy *self, PyObject *args, PyObject *k
   int f;
   static char const * kwlist[] = {"f", "metric", NULL};
   if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i|s", (char**)kwlist, &f, &metric))
-    return (int) NULL;
+    return 0;
   return 0;
 }
 
