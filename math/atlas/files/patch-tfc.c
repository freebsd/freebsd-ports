http://math-atlas.sourceforge.net/errata.html
Install dies in tfc / ?Xover.h is incomplete
--- tune/blas/gemm/tfc.c	Mon Dec 22 09:11:57 2003
+++ tune/blas/gemm/tfc.c	Wed Mar  7 02:01:20 2007
@@ -55,7 +55,7 @@
 double time00();
 
 #define DENMAT 175
-#define MAXALLOC (3*1024*1024*8)
+#define MAXALLOC (8*1024*1024*8)
 
 #ifdef ATL_DeclareSlens
 F77_INTEGER ATL_Slen1, ATL_Slen2;
