--- freetype_wrap.c.orig	Mon May 22 23:21:55 2006
+++ freetype_wrap.c	Mon May 22 23:22:11 2006
@@ -3410,7 +3410,7 @@
     PyObject * _argo0 = 0;
 
     self = self;
-    if(!PyArg_ParseTuple(args,"Oh:TT_Char_Index",&_argo0,&_arg1)) 
+    if(!PyArg_ParseTuple(args,"OH:TT_Char_Index",&_argo0,&_arg1)) 
         return NULL;
     if (_argo0) {
         if (_argo0 == Py_None) { _arg0 = NULL; }
