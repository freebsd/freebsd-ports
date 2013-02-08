--- examples/tk/xtk02.c.orig
+++ examples/tk/xtk02.c
@@ -49,7 +49,7 @@
         pm->fdata[i] = y;
     }
 
-    interp->result = "Things are cool in gumbyville.";
+    Tcl_SetResult(interp,(char*)"Things are cool in gumbyville.",TCL_VOLATILE);
     return TCL_OK;
 }
 
@@ -82,7 +82,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
