--- main.cc.orig	2013-05-21 15:33:25.000000000 +0200
+++ main.cc	2013-05-21 15:40:33.000000000 +0200
@@ -222,7 +222,7 @@
 
 static int cmd_version(ClientData , Tcl_Interp* tcl, int , CONST84 char **)
 {
-	tcl->result = version;
+    Tcl_SetObjResult(tcl, Tcl_NewStringObj(version, -1));
 	return (TCL_OK);
 }
 
@@ -331,7 +331,7 @@
 
 	Tcl_Interp *interp = Tcl_CreateInterp();
 	if (Tcl_Init(interp) == TCL_ERROR) {
-		printf("%s\n", interp->result);
+		printf("%s\n", Tcl_GetStringResult(interp));
 		abort();
 	}
 
@@ -350,7 +350,7 @@
 #endif
 
 	if (Otcl_Init(interp) == TCL_ERROR) {
-		printf("%s\n", interp->result);
+		printf("%s\n", Tcl_GetStringResult(interp));
 		abort();
 	}
 #ifdef HAVE_LIBTCLDBG
@@ -372,7 +372,7 @@
 	if (Tk_Init(tcl.interp()) == TCL_OK)
 		tk = Tk_MainWindow(tcl.interp());
 	if (tk == 0) {
-		fprintf(stderr, "nam: %s\n", interp->result);
+		fprintf(stderr, "nam: %s\n", Tcl_GetStringResult(interp));
 		exit(1);
 	}
 	tcl.tkmain(tk);
