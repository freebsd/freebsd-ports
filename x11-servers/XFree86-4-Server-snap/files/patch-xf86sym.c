--- programs/Xserver/hw/xfree86/loader/xf86sym.c.orig	Wed Feb 26 15:08:02 2003
+++ programs/Xserver/hw/xfree86/loader/xf86sym.c	Wed May 21 08:47:39 2003
@@ -106,6 +106,14 @@
 extern void* __remqu(long, long);
 #endif
 
+#if defined(__sparc__) && defined(__FreeBSD__)
+extern float _Qp_qtos(unsigned int *);
+extern double _Qp_qtod(unsigned int *);
+extern unsigned long long _Qp_qtoux(unsigned int *);
+extern void _Qp_dtoq(unsigned int *, double);
+extern void _Qp_uitoq(unsigned int *, unsigned int);
+#endif
+
 #if defined(__GNUC__)
 extern long __div64(long, long);
 extern long __divdf3(long, long);
@@ -1066,6 +1074,13 @@
 
 #ifdef __FreeBSD__
    SYMFUNC(sysctlbyname)
+#if defined(__sparc__)
+   SYMFUNC(_Qp_qtos)
+   SYMFUNC(_Qp_qtod)
+   SYMFUNC(_Qp_qtoux)
+   SYMFUNC(_Qp_uitoq)
+   SYMFUNC(_Qp_dtoq)
+#endif
 #endif
 
 /*
