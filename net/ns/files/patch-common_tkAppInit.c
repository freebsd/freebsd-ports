--- common/tkAppInit.cc.orig	2014-01-17 10:37:16.000000000 +0100
+++ common/tkAppInit.cc	2014-01-17 10:38:11.000000000 +0100
@@ -293,7 +293,6 @@
 Tcl_AppInit(Tcl_Interp *interp)
 {
 #ifdef MEMDEBUG_SIMULATIONS
-        extern MemTrace *globalMemTrace;
         globalMemTrace = new MemTrace;
 #endif
 
