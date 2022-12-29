--- CONFIG/src/SpewMakeInc.c.orig	2016-07-28 19:43:00 UTC
+++ CONFIG/src/SpewMakeInc.c
@@ -469,7 +469,8 @@ int main(int nargs, char **args)
             &outfile, &srcdir, &blddir, &USEDEFL1, &USEARCHDEF, &USEIEEE,
             &LATUNE, &nof77, &lapackref, &f2cdefs, &cdefs, &pmake, &flapack,
             &smaflags, &dmaflags, &f77lib, &ADd, &l2size, &targ);
-   if (ncpu > 1) THREADS = 1;
+/*   if (ncpu > 1) THREADS = 1; */
+   THREADS = 1;
    if (!outfile)
       fpout = stdout;
    else
@@ -555,7 +556,7 @@ int main(int nargs, char **args)
    fprintf(fpout, "#  -------------------------------------------------\n");
    fprintf(fpout, "#  Name indicating the platform to configure BLAS to\n");
    fprintf(fpout, "#  -------------------------------------------------\n");
-   fprintf(fpout, "   ARCH = %s", machnam[mach]);
+   fprintf(fpout, "   ATLAS_ARCH = %s", machnam[mach]);
    fprintf(fpout, "%d", ptrbits);
    #if defined(__powerpc64__) && defined(__ORDER_LITTLE_ENDIAN__)
       fprintf(fpout, "LE");
@@ -783,7 +784,7 @@ int main(int nargs, char **args)
    fprintf(fpout, "\n");
    fprintf(fpout, "   KC = $(DKC)\n   KCFLAGS = $(CDEFS) $(DKCFLAGS)\n");
 
-   fprintf(fpout, "   LDFLAGS =");
+   fprintf(fpout, "   LDFLAGS = %%LDFLAGS%% ");
    if (MachIsX86(mach))
    {
       if (OSIsWin(OS))
@@ -815,7 +816,7 @@ int main(int nargs, char **args)
    if (USEMINGW)
       fprintf(fpout, "\n   ARCHIVER = $(BLDdir)/mgwar\n");
    else
-      fprintf(fpout, "\n   ARCHIVER = ar\n");
+      fprintf(fpout, "\n   ARCHIVER = $(AR)\n");
    fprintf(fpout, "   ARFLAGS  = r\n");
 /*
  * JF Mertens says that even x86 OS X still need ranlib for safety
@@ -846,7 +847,7 @@ int main(int nargs, char **args)
    else if (lapackref) fprintf(fpout, "$(FLAdir)/lapack_$(ARCH).a");
    fprintf(fpout, "\n");
    fprintf(fpout, "   SBLASlib = $(FBLASlib)  # should be serial sysblas\n");
-   fprintf(fpout, "   BLASlib = $(FBLASlib)   # should be parallel sysblas\n");
+   fprintf(fpout, "   BLASlib = $(BLAS)   # should be parallel sysblas\n");
    fprintf(fpout, "   SLAPACKlib =   # set to parallel system lapack\n");
    fprintf(fpout, "   SSLAPACKlib =  # set to serial system lapack\n");
    if (THREADS)
