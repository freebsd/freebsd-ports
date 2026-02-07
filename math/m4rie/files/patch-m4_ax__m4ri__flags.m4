--- m4/ax_m4ri_flags.m4.orig	2025-01-26 11:38:37 UTC
+++ m4/ax_m4ri_flags.m4
@@ -34,7 +34,7 @@ AC_DEFUN([AX_M4RI_CFLAGS], 
       [[
   FILE *f;
   f = fopen("conftest_m4ri_cflags", "w"); if (!f) return 1;
-  fprintf(f,"%s %s",__M4RI_SIMD_CFLAGS, __M4RI_OPENMP_CFLAGS);
+  fprintf(f,"%s",__M4RI_OPENMP_CFLAGS);
   fclose(f);
   return 0;
    ]])],
