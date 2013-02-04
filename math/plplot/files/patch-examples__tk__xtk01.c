--- examples/tk/xtk01.c.orig
+++ examples/tk/xtk01.c
@@ -53,7 +53,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
