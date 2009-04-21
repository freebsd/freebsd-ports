--- CONFIG/src/SpewMakeInc.c.orig	2009-04-07 23:11:39.000000000 +0900
+++ CONFIG/src/SpewMakeInc.c	2009-04-13 17:20:56.000000000 +0900
@@ -737,7 +737,7 @@
    fprintf(fpout, "#  ------------------------------------\n");
    fprintf(fpout, "#  Reference and system libraries\n");
    fprintf(fpout, "#  ------------------------------------\n");
-   fprintf(fpout, "   FBLASlib = $(LIBdir)/libf77refblas.a\n");
+   fprintf(fpout, "   FBLASlib = -L%%LOCALBASE%%/lib -lblas\n");
    fprintf(fpout, "   BLASlib = $(FBLASlib)\n");
    if (LAsrcd)
    {
@@ -754,7 +754,7 @@
    fprintf(fpout, "   SLAPACKlib = \n");
    if (THREADS)
    {
-      fprintf(fpout, "   LIBS = -lpthread");
+      fprintf(fpout, "   LIBS = %%PTHREAD_LIBS%%");
       if (OSIsWin(OS))
          fprintf(fpout, " -lkernel32");
    }
