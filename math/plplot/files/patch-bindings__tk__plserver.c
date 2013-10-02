--- bindings/tk/plserver.c.orig	2013-04-26 12:02:06.000000000 +0200
+++ bindings/tk/plserver.c	2013-10-01 22:49:59.000000000 +0200
@@ -158,7 +158,7 @@
 //
 // Results:
 //	Returns a standard Tcl completion code, and leaves an error
-//	message in interp->result if an error occurs.
+//	message in Tcl_GetStringResult(interp) if an error occurs.
 //
 // Side effects:
 //	Depends on the startup script.
