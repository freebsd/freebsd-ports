--- common/tclAppInit.cc.orig	2014-01-17 10:38:38.000000000 +0100
+++ common/tclAppInit.cc	2014-01-17 10:38:45.000000000 +0100
@@ -237,7 +237,6 @@
 Tcl_AppInit(Tcl_Interp *interp)
 {
 #ifdef MEMDEBUG_SIMULATIONS
-        extern MemTrace *globalMemTrace;
         globalMemTrace = new MemTrace;
 #endif
 
