--- bindings/tk/plframe.c.orig	2012-08-14 00:14:23.000000000 +0200
+++ bindings/tk/plframe.c	2013-10-01 22:47:19.000000000 +0200
@@ -2218,7 +2218,7 @@
 //
 // Results:
 //	The return value is a standard Tcl result.  If TCL_ERROR is
-//	returned, then interp->result contains an error message.
+//	returned, then Tcl_GetStringResult(interp) contains an error message.
 //
 // Side effects:
 //	Configuration information, such as text string, colors, font, etc.
