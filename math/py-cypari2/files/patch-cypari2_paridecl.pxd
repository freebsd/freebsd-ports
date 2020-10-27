--- cypari2/paridecl.pxd.orig	2019-04-23 10:57:51 UTC
+++ cypari2/paridecl.pxd
@@ -3850,7 +3850,7 @@ cdef extern from *:     # PARI headers already include
     GEN     glcm0(GEN x, GEN y)
     GEN     gp_factor0(GEN x, GEN flag)
     GEN     idealfactorback(GEN nf, GEN L, GEN e, int red)
-    long    isirreducible(GEN x)
+    long    polisirreducible "isirreducible"(GEN x)
     GEN     newtonpoly(GEN x, GEN p)
     GEN     nffactorback(GEN nf, GEN L, GEN e)
     GEN     nfrootsQ(GEN x)
