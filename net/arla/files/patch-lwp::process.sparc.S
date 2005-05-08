--- lwp/process.sparc.S.orig	Sun May  8 12:22:07 2005
+++ lwp/process.sparc.S	Sun May  8 12:21:15 2005
@@ -30,6 +30,13 @@
 #endif
 
 
+#if !defined(ST_FLUSHWIN)
+#if !defined(T_FLUSHWIN)
+#define	T_FLUSHWIN	0x83	/* flush windows */
+#endif
+#define	ST_FLUSHWIN	(T_FLUSHWIN & 0x7f)
+#endif
+
 #if defined(AFS_SUN5_ENV)
 #include <sys/asm_linkage.h>
 #include <sys/trap.h>
