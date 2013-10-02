--- examples/tk/xtk04.c.orig	2011-11-30 23:04:42.000000000 +0100
+++ examples/tk/xtk04.c	2013-10-01 23:08:24.000000000 +0200
@@ -87,7 +87,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
