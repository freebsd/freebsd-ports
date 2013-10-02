--- examples/tk/xtk02.c.orig	2011-11-30 23:04:42.000000000 +0100
+++ examples/tk/xtk02.c	2013-10-01 23:06:58.000000000 +0200
@@ -85,7 +85,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
