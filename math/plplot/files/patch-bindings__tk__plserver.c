--- bindings/tk/plserver.c.orig
+++ bindings/tk/plserver.c
@@ -126,11 +126,11 @@
     if ( Tk_ParseArgv( interp, (Tk_Window) NULL, &argc, argv,
              argTable, TK_ARGV_NO_DEFAULTS ) != TCL_OK )
     {
-        fprintf( stderr, "\n(plserver) %s\n\n", interp->result );
+        fprintf( stderr, "\n(plserver) %s\n\n", Tcl_GetStringResult(interp) );
         fprintf( stderr, "\
 The client_<xxx> and -child options should not be used except via the\n\
 PLplot/Tk driver.\n\n(wish) " );
-        if ( strncmp( interp->result, helpmsg, strlen( helpmsg ) ) )
+        if ( strncmp( Tcl_GetStringResult(interp), helpmsg, strlen( helpmsg ) ) )
             exit( 1 );
     }
 
@@ -158,7 +158,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
@@ -257,8 +257,8 @@
 
 // Print error message if one given
 
-    if ( interp->result != NULL && interp->result[0] != '\0' )
-        fprintf( stderr, "%s\n", interp->result );
+    if ( Tcl_GetStringResult(interp) != NULL && Tcl_GetStringResult(interp)[0] != '\0' )
+        fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
 
 // Best to check the syntax before proceeding
 
