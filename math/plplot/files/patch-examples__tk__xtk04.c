--- examples/tk/xtk04.c.orig
+++ examples/tk/xtk04.c
@@ -35,7 +35,7 @@
         if ( pm->fdata[i] > max )
             max = pm->fdata[i];
 
-    sprintf( interp->result, "%f", max );
+    sprintf( Tcl_GetStringResult(interp), "%f", max );
     return TCL_OK;
 }
 
@@ -48,7 +48,7 @@
         if ( pm->fdata[i] < min )
             min = pm->fdata[i];
 
-    sprintf( interp->result, "%f", min );
+    sprintf( Tcl_GetStringResult(interp), "%f", min );
     return TCL_OK;
 }
 
@@ -80,7 +80,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
@@ -158,7 +158,7 @@
 
     if ( pm->dim != 2 )
     {
-        interp->result = "must use 2-d matrix.";
+        Tcl_SetResult(interp,(char*)"must use 2-d matrix.",TCL_VOLATILE);
         return TCL_ERROR;
     }
 
