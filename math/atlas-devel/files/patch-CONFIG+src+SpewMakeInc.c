--- CONFIG/src/SpewMakeInc.c~	Tue Dec 19 06:47:11 2006
+++ CONFIG/src/SpewMakeInc.c	Wed Dec 27 17:05:12 2006
@@ -588,7 +588,7 @@
    if (flapack) fprintf(fpout, "%s", flapack);
    fprintf(fpout, "\n");
    if (THREADS)
-      fprintf(fpout, "   LIBS = -lpthread -lm\n\n");
+      fprintf(fpout, "   LIBS = %%PTHREAD_LIBS%% -lm\n\n");
    else
       fprintf(fpout, "   LIBS = -lm\n\n");
 
