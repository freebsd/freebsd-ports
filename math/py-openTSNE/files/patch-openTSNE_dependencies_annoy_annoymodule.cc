--- openTSNE/dependencies/annoy/annoymodule.cc.orig	2024-11-08 03:59:50 UTC
+++ openTSNE/dependencies/annoy/annoymodule.cc
@@ -177,7 +177,7 @@ py_an_init(py_annoy *self, PyObject *args, PyObject *k
   int f;
   static char const * kwlist[] = {"f", "metric", NULL};
   if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i|s", (char**)kwlist, &f, &metric))
-    return (int) NULL;
+    return 0;
   return 0;
 }
 
