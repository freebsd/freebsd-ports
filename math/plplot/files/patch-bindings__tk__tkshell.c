--- bindings/tk/tkshell.c.orig
+++ bindings/tk/tkshell.c
@@ -115,7 +115,7 @@
         if ( Tcl_ExprBoolean( interp, argv[1], &result ) )
         {
             fprintf( stderr, "wait_until command \"%s\" failed:\n\t %s\n",
-                argv[1], interp->result );
+                argv[1], Tcl_GetStringResult(interp) );
             break;
         }
         if ( result )
