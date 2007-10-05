--- ps/ps.c.orig	2007-10-05 15:41:41.000000000 +0200
+++ ps/ps.c	2007-10-05 15:43:31.000000000 +0200
@@ -88,6 +88,9 @@
 #define	proc	process
 #undef	p_pgid
 #undef	p_pctcpu
+#if !defined(PS_SWAPPINGOUT) && defined(P_SWAPPINGOUT)
+#define PS_SWAPPINGOUT P_SWAPPINGOUT
+#endif
 #if defined (__DragonFly__)
 #endif	/* __DragonFly__ */
 #elif defined (__hpux)
