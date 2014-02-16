--- bindings/tk/tkMain.c.orig	2013-12-18 20:25:14.000000000 -0500
+++ bindings/tk/tkMain.c
@@ -92,10 +92,6 @@ EXTERN int Tcl_Import _ANSI_ARGS_( ( Tcl
                                      int allowOverwrite ) );
 #endif
 
-#ifndef Tcl_GetGlobalNamespace_TCL_DECLARE
-EXTERN Tcl_Namespace * Tcl_GetGlobalNamespace _ANSI_ARGS_( (
-                                                               Tcl_Interp * interp ) );
-#endif
 
 //
 // Declarations for various library procedures and variables (don't want
