--- CONFIG/src/SpewMakeInc.c.orig	2011-05-14 13:33:24.000000000 -0400
+++ CONFIG/src/SpewMakeInc.c	2011-09-06 06:06:00.000000000 -0400
@@ -399,7 +399,8 @@
             &mhz, &ptrbits, &ncpu, comps, &gccflags, &outfile, &srcdir,
             &blddir, &USEDEFL1, &USEARCHDEF, &nof77, &f2cdefs, &cdefs, &pmake,
             &flapack, &smaflags, &dmaflags, &f77lib, &l2size, &targ);
-   if (ncpu > 1) THREADS = 1;
+ /*   if (ncpu > 1) THREADS = 1; */
+    THREADS = 1;
    if (!outfile)
       fpout = stdout;
    else
@@ -482,7 +483,7 @@
    fprintf(fpout, "#  -------------------------------------------------\n");
    fprintf(fpout, "#  Name indicating the platform to configure BLAS to\n");
    fprintf(fpout, "#  -------------------------------------------------\n");
-   fprintf(fpout, "   ARCH = %s", machnam[mach]);
+   fprintf(fpout, "   ATLAS_ARCH = %s", machnam[mach]);
    fprintf(fpout, "%d", ptrbits);
    if (ISAX)
       fprintf(fpout, "%s", ISAXNAM[ISAX]);
@@ -649,7 +650,7 @@
           comps[i][j-2] == 'c' && comps[i][j-1] == 'c')
          break;
    }
-   goodgcc = (j < NCOMP) ? comps[j] : "gcc";
+   goodgcc = (j < NCOMP) ? comps[j] : "%%CC%%";
    fprintf(fpout, "   GOODGCC = %s", goodgcc);
    if (gccflags)
       fprintf(fpout, " %s", gccflags);
@@ -661,7 +662,7 @@
        fprintf(fpout, " %s", sp);
    fprintf(fpout, "\n");
 
-   fprintf(fpout, "   LDFLAGS =");
+   fprintf(fpout, "   LDFLAGS = %%LDFLAGS%% ");
    if (MachIsX86(mach))
    {
       if (ptrbits == 32)
@@ -679,7 +680,7 @@
    fprintf(fpout, "   FCLINKFLAGS = $(FLINKFLAGS)");
    if (strstr(comps[F77_], "ifort") && !OSIsWin(OS))
       fprintf(fpout, " -nofor_main");
-   fprintf(fpout, "\n   ARCHIVER = ar\n");
+   fprintf(fpout, "\n   ARCHIVER = $(AR)\n");
    fprintf(fpout, "   ARFLAGS  = r\n");
 /*
  * JF Mertens says that even x86 OS X still need ranlib for safety
@@ -702,14 +703,14 @@
    fprintf(fpout, "#  ------------------------------------\n");
    fprintf(fpout, "#  Reference and system libraries\n");
    fprintf(fpout, "#  ------------------------------------\n");
-   fprintf(fpout, "   BLASlib = \n");
-   fprintf(fpout, "   FBLASlib = \n");
+   fprintf(fpout, "   BLASlib = $(BLAS)\n");
+   fprintf(fpout, "   FBLASlib = $(BLAS)\n");
    fprintf(fpout, "   FLAPACKlib = ");
    if (flapack) fprintf(fpout, "%s", flapack);
    fprintf(fpout, "\n");
    fprintf(fpout, "   SLAPACKlib = \n");
    if (THREADS)
-      fprintf(fpout, "   LIBS = -lpthread");
+      fprintf(fpout, "   LIBS = %%PTHREAD_LIBS%%");
    else
       fprintf(fpout, "   LIBS =");
    if (!OSIsWin(OS))
