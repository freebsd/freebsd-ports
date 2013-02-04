--- bindings/tk/tkMain.c.orig
+++ bindings/tk/tkMain.c
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
@@ -180,7 +169,7 @@
 pltkMain( int argc, const char **argv, char *RcFileName,
           int ( *AppInit )( Tcl_Interp *interp ) )
 {
-    char       *args, *msg;
+    char       *args; const char *msg;
     const char *p;
     char       buf[20];
     int        code;
@@ -202,7 +191,7 @@
     if ( Tk_ParseArgv( interp, (Tk_Window) NULL, &argc, argv, argTable, 0 )
          != TCL_OK )
     {
-        fprintf( stderr, "%s\n", interp->result );
+        fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
         exit( 1 );
     }
     if ( name == NULL )
@@ -331,7 +320,7 @@
 
     if ( ( *AppInit )( interp ) != TCL_OK )
     {
-        fprintf( stderr, "(*AppInit) failed: %s\n", interp->result );
+        fprintf( stderr, "(*AppInit) failed: %s\n", Tcl_GetStringResult(interp) );
     }
 
     //
@@ -343,7 +332,7 @@
         code = Tcl_VarEval( interp, "wm geometry . ", geometry, (char *) NULL );
         if ( code != TCL_OK )
         {
-            fprintf( stderr, "%s\n", interp->result );
+            fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
         }
     }
 
@@ -393,7 +382,7 @@
             fullName = Tcl_TildeSubst( interp, RcFileName, &buffer );
             if ( fullName == NULL )
             {
-                fprintf( stderr, "%s\n", interp->result );
+                fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
             }
             else
             {
@@ -403,7 +392,7 @@
                     code = Tcl_EvalFile( interp, fullName );
                     if ( code != TCL_OK )
                     {
-                        fprintf( stderr, "%s\n", interp->result );
+                        fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
                     }
                     fclose( f );
                 }
@@ -442,7 +431,7 @@
     msg = (char *) Tcl_GetVar( interp, "errorInfo", TCL_GLOBAL_ONLY );
     if ( msg == NULL )
     {
-        msg = interp->result;
+        msg = Tcl_GetStringResult(interp);
     }
     fprintf( stderr, "%s\n", msg );
     Tcl_Eval( interp, errorExitCmd );
@@ -535,11 +524,11 @@
     Tk_CreateFileHandler( 0, TK_READABLE, StdinProc, (ClientData) 0 );
 #endif
     Tcl_DStringFree( &command );
-    if ( *interp->result != 0 )
+    if ( Tcl_GetStringResult(interp) )
     {
         if ( ( code != TCL_OK ) || ( tty ) )
         {
-            printf( "%s\n", interp->result );
+            printf( "%s\n", Tcl_GetStringResult(interp) );
         }
     }
 
@@ -599,7 +588,7 @@
         {
             Tcl_AddErrorInfo( interp,
                 "\n    (script that generates prompt)" );
-            fprintf( stderr, "%s\n", interp->result );
+            fprintf( stderr, "%s\n", Tcl_GetStringResult(interp) );
             goto defaultPrompt;
         }
     }
