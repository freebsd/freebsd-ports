--- Lib/proto.h.orig	Thu Dec 12 13:47:59 2002
+++ Lib/proto.h	Tue Aug 12 22:53:22 2003
@@ -456,7 +456,9 @@
  void saxpy(long, float, float *, long, float *, long); 
  void RandomPermute(long, idxtype *, long); 
  double drand48(); 
+#if !defined(__FreeBSD__)
  void srand48(long); 
+#endif
  long ispow2(long); 
  void InitRandom(long); 
  long log2(long); 
