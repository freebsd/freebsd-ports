- see https://github.com/pavlin-policar/openTSNE/issues/165

--- openTSNE/dependencies/annoy/annoymodule.cc.orig	2021-03-13 20:45:35 UTC
+++ openTSNE/dependencies/annoy/annoymodule.cc
@@ -177,7 +177,7 @@ py_an_init(py_annoy *self, PyObject *args, PyObject *k
   int f;
   static char const * kwlist[] = {"f", "metric", NULL};
   if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i|s", (char**)kwlist, &f, &metric))
-    return (int) NULL;
+    return 0;
   return 0;
 }
 
