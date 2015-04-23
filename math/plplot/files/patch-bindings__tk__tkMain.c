--- bindings/tk/tkMain.c.orig	2015-04-12 10:08:04 UTC
+++ bindings/tk/tkMain.c
@@ -90,10 +90,6 @@ EXTERN int Tcl_Import _ANSI_ARGS_( ( Tcl
                                      int allowOverwrite ) );
 #endif
 
-#ifndef Tcl_GetGlobalNamespace_TCL_DECLARE
-EXTERN Tcl_Namespace * Tcl_GetGlobalNamespace _ANSI_ARGS_( (
-                                                               Tcl_Interp * interp ) );
-#endif
 
 //
 // Declarations for various library procedures and variables (don't want
