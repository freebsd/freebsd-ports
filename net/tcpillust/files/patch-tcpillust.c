--- tcpillust.c.orig	2013-07-08 14:06:59.000000000 +0200
+++ tcpillust.c	2013-07-08 14:09:05.000000000 +0200
@@ -93,16 +93,16 @@
 	interp = Tcl_CreateInterp();
   
 	if (Tcl_Init(interp) == TCL_ERROR) {
-		fprintf(stderr, "Tcl_Init failed:  %s\n", interp->result);
+		fprintf(stderr, "Tcl_Init failed:  %s\n", Tcl_GetStringResult(interp));
 		exit(-1);
 	}
 	if (Tk_Init(interp) == TCL_ERROR) {
-		fprintf(stderr, "Tk_Init failed:  %s\n", interp->result);
+		fprintf(stderr, "Tk_Init failed:  %s\n", Tcl_GetStringResult(interp));
 		exit(-1);
 	}
 	main_tkwin = Tk_MainWindow(interp);
 	if (main_tkwin == NULL) {
-		fprintf(stderr, "%s\n", interp->result);
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 		exit(-1);
 	}
 
@@ -169,12 +169,12 @@
 {
 	canvas_tkwin = Tk_NameToWindow(interp, ".subframe1.canvas", main_tkwin);
 	if (canvas_tkwin == NULL) {
-		fprintf(stderr, "%s\n", interp->result);
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 		exit(-1);
 	}
 	subcanvas_tkwin = Tk_NameToWindow(interp, ".subframe2.canvas", main_tkwin);
 	if (subcanvas_tkwin == NULL) {
-		fprintf(stderr, "%s\n", interp->result);
+		fprintf(stderr, "%s\n", Tcl_GetStringResult(interp));
 		exit(-1);
 	}
 
