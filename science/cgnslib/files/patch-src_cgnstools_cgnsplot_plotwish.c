--- ./src/cgnstools/cgnsplot/plotwish.c.orig	2011-02-12 23:50:31.000000000 +0100
+++ ./src/cgnstools/cgnsplot/plotwish.c	2012-03-13 22:19:20.000000000 +0100
@@ -20,8 +20,10 @@
  * Sun shared libraries to be used for Tcl.
  */
 
+#ifndef __FreeBSD__
 extern int matherr();
 int *tclDummyMathPtr = (int *) matherr;
+#endif /* FreeBSD test */
 
 extern int Cgnstcl_Init _ANSI_ARGS_((Tcl_Interp *interp));
 extern int Tkogl_Init _ANSI_ARGS_((Tcl_Interp *interp));
