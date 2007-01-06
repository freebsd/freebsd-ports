--- CONFIG/src/SpewMakeInc.c.orig	Sat Jan  6 13:57:34 2007
+++ CONFIG/src/SpewMakeInc.c	Sat Jan  6 13:58:21 2007
@@ -582,13 +582,13 @@
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
-      fprintf(fpout, "   LIBS = -lpthread -lm\n\n");
+      fprintf(fpout, "   LIBS = %%PTHREAD_LIBS%% -lm\n\n");
    else
       fprintf(fpout, "   LIBS = -lm\n\n");
 
