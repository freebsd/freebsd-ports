--- CONFIG/src/SpewMakeInc.c.orig	2007-08-11 00:57:42.000000000 +0900
+++ CONFIG/src/SpewMakeInc.c	2007-09-29 22:03:26.000000000 +0900
@@ -665,13 +665,13 @@
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
    if (THREADS)
-      fprintf(fpout, "   LIBS = -lpthread");
+      fprintf(fpout, "   LIBS = %%PTHREAD_LIBS%%");
    else
       fprintf(fpout, "   LIBS =");
    if (!OSIsWin(OS))
