--- iflib/clibrary.h.orig	Sat Sep 11 17:16:11 1993
+++ iflib/clibrary.h	Mon Jul 22 19:38:20 2002
@@ -102,9 +102,11 @@
 extern FREEVAL		free();
 extern POINTER		malloc();
 extern POINTER		realloc();
+#ifndef __FreeBSD__
 #if	defined(ACT_MMAP)
 extern char		*mmap();
 #endif	/* defined(ACT_MMAP) */
+#endif
 
 /* Some backward systems need this. */
 extern FILE	*popen();
@@ -121,8 +123,10 @@
 extern void	exit();
 /* =()<extern @<GETPIDVAL>@	getpid();>()= */
 extern int	getpid();
+#ifndef __FreeBSD__
 /* =()<extern @<LSEEKVAL>@	lseek();>()= */
 extern long	lseek();
+#endif
 /* =()<extern @<QSORTVAL>@	qsort();>()= */
 extern int	qsort();
 /* =()<extern @<SLEEPVAL>@	sleep();>()= */
