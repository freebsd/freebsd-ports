--- src/cgnstools/cgnsview/cgiowish.c.orig	2017-07-17 21:51:06 UTC
+++ src/cgnstools/cgnsview/cgiowish.c
@@ -20,8 +20,10 @@
  * Sun shared libraries to be used for Tcl.
  */
 
+#ifndef __FreeBSD__
 extern int matherr();
 int *tclDummyMathPtr = (int *) matherr;
+#endif /* FreeBSD test */
 
 #ifdef TK_TEST
 extern int		Tcltest_Init _ANSI_ARGS_((Tcl_Interp *interp));
