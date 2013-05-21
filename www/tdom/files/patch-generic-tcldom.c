--- ../generic/tcldom.c.orig	2013-05-13 11:36:27.000000000 +0200
+++ ../generic/tcldom.c	2013-05-13 11:39:00.000000000 +0200
@@ -5934,7 +5934,7 @@
     if (ret == TCL_ERROR) {
         char msg[64 + TCL_INTEGER_SPACE];
         sprintf(msg, "\n    (\"%s %s\" body line %d)", Tcl_GetString(objv[0]),
-                Tcl_GetString(objv[1]), interp->errorLine);
+                Tcl_GetString(objv[1]), Tcl_GetErrorLine(interp));
         Tcl_AddErrorInfo(interp, msg);
     }
 
