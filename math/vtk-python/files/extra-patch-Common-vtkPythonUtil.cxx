--- Common/vtkPythonUtil.cxx.orig	Thu Oct 12 03:11:22 2006
+++ Common/vtkPythonUtil.cxx	Thu Oct 12 03:11:33 2006
@@ -731,7 +731,7 @@
     }
   if (strcmp(name, "__doc__") == 0)
     {
-    char *doc = t->tp_doc;
+    const char *doc = t->tp_doc;
     if (doc != NULL)
       {
       return PyString_FromString(doc);
