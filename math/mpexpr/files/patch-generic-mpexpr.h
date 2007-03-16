--- generic/mpexpr.h.orig	Thu Mar 15 03:21:12 2007
+++ generic/mpexpr.h	Thu Mar 15 03:21:46 2007
@@ -100,8 +100,8 @@
 
 /* mpexpr  tcl command procs */
 
-EXTERN Tcl_CmdProc      Mp_ExprCmd;
-EXTERN Tcl_CmdProc      Mp_FormatCmd;
+EXTERN int Mp_ExprCmd(ClientData, Tcl_Interp *interp, int argc, char **argv);
+EXTERN int Mp_FormatCmd(ClientData, Tcl_Interp *interp, int argc, char **argv);
 
 
 #endif 
