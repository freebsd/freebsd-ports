--- generic/mpiface.c.orig	2016-09-16 07:36:35 UTC
+++ generic/mpiface.c
@@ -69,7 +69,7 @@ Mpexpr_Init (interp)
     Tcl_Interp *interp;
 {
     Mp_Data *mdPtr;
-    static initialized = 0;
+    static int initialized = 0;
     TCL_DECLARE_MUTEX(mpMutex)
 
     if (!initialized) {
