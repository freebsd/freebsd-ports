--- ./src/cgnstools/cgnsview/cgiowish.c.orig	2011-02-12 23:47:39.000000000 +0100
+++ ./src/cgnstools/cgnsview/cgiowish.c	2012-03-13 22:04:59.000000000 +0100
@@ -20,8 +20,10 @@
  * Sun shared libraries to be used for Tcl.
  */
 
+#ifndef __FreeBSD__
 extern int matherr();
 int *tclDummyMathPtr = (int *) matherr;
+#endif /* FreeBSD test */
 
 #ifdef TK_TEST
 extern int		Tcltest_Init _ANSI_ARGS_((Tcl_Interp *interp));
