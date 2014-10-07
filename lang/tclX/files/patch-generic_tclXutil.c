--- generic/tclXutil.c.orig	2014-07-30 16:56:00.000000000 +0200
+++ generic/tclXutil.c	2014-07-30 16:56:50.000000000 +0200
@@ -870,7 +870,7 @@
 TclX_IsNullObj (objPtr)
     Tcl_Obj *objPtr;
 {
-    static Tcl_ObjType *listType = NULL, *stringType = NULL;
+    const static Tcl_ObjType *listType = NULL, *stringType = NULL;
     int length;
     
     /*
@@ -956,7 +956,7 @@
 {
     Tcl_Obj **saveObjv;
     int saveObjc;
-    long flags;
+    long flags = 0;
 
     if ((Tcl_ListObjGetElements (NULL, saveObjPtr, &saveObjc,
                                  &saveObjv) != TCL_OK) ||
