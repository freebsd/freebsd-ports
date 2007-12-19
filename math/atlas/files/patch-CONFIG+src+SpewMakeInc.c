--- CONFIG/src/SpewMakeInc.c.orig	2007-10-11 05:40:21.000000000 +0900
+++ CONFIG/src/SpewMakeInc.c	2007-10-29 11:03:11.000000000 +0900
@@ -693,14 +693,14 @@
    fprintf(fpout, "#  ------------------------------------\n");
    fprintf(fpout, "#  Reference and system libraries\n");
    fprintf(fpout, "#  ------------------------------------\n");
-   fprintf(fpout, "   BLASlib = \n");
-   fprintf(fpout, "   FBLASlib = \n");
-   fprintf(fpout, "   FLAPACKlib = ");
+   fprintf(fpout, "   BLASlib = -L%%LOCALBASE%%/lib -lblas\n");
+   fprintf(fpout, "   FBLASlib = -L%%LOCALBASE%%/lib -lblas\n");
+   fprintf(fpout, "   FLAPACKlib = -L%%LOCALBASE%%/lib -llapack");
    if (flapack) fprintf(fpout, "%s", flapack);
    fprintf(fpout, "\n");
    fprintf(fpout, "   SLAPACKlib = \n");
    if (THREADS)
-      fprintf(fpout, "   LIBS = -lpthread");
+      fprintf(fpout, "   LIBS = %%PTHREAD_LIBS%%");
    else
       fprintf(fpout, "   LIBS =");
    if (!OSIsWin(OS))
