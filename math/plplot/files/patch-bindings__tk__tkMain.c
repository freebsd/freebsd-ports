--- bindings/tk/tkMain.c.orig	2013-01-30 00:36:01.000000000 +0100
+++ bindings/tk/tkMain.c	2013-10-01 22:51:31.000000000 +0200
@@ -85,17 +85,6 @@
 
 // From tclIntDecls.h
 
-#ifndef Tcl_Import_TCL_DECLARED
-EXTERN int Tcl_Import _ANSI_ARGS_( ( Tcl_Interp * interp,
-                                     Tcl_Namespace * nsPtr, char * pattern,
-                                     int allowOverwrite ) );
-#endif
-
-#ifndef Tcl_GetGlobalNamespace_TCL_DECLARE
-EXTERN Tcl_Namespace * Tcl_GetGlobalNamespace _ANSI_ARGS_( (
-                                                               Tcl_Interp * interp ) );
-#endif
-
 //
 // Declarations for various library procedures and variables (don't want
 // to include tkInt.h or tkConfig.h here, because people might copy this
