--- src/tkAppInit.c.orig	Thu Mar 15 10:00:05 2007
+++ src/tkAppInit.c	Thu Mar 15 10:00:12 2007
@@ -97,9 +97,6 @@
  * Sun shared libraries to be used for Tcl.
  */
 
-extern int matherr();
-void GetDspStatus();
-int *tclDummyMathPtr = (int *) matherr;
 
 /***************************************************************************/
 /* fork and initiate server process */
