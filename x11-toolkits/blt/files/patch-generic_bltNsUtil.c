--- generic/bltNsUtil.c.orig	2013-11-18 17:04:03.000000000 +0100
+++ generic/bltNsUtil.c	2013-11-18 17:11:18.000000000 +0100
@@ -27,6 +27,7 @@
 
 #include "bltInt.h"
 #include "bltList.h"
+#include <tclInt.h>
 
 /* Namespace related routines */
 
@@ -62,7 +63,7 @@
     Tcl_Var varPtr;
     Tcl_Namespace *nsPtr;
     Tcl_Obj *objPtr;
-    char *str, *cp;
+    const char *str, *cp;
 
     varPtr = Tcl_FindNamespaceVar(interp, (char *)name, 
 	(Tcl_Namespace *)NULL, 0);
@@ -72,7 +73,7 @@
     objPtr = Tcl_NewObj();
     Tcl_GetVariableFullName(interp, varPtr, objPtr);
     str = Tcl_GetString(objPtr);
-    if (Blt_ParseQualifiedName(interp, str, &nsPtr, &cp) == NULL) {
+    if (Blt_ParseQualifiedName(interp, str, &nsPtr, &cp) != TCL_OK) {
         nsPtr = NULL;
     }
     Tcl_DecrRefCount(objPtr);
