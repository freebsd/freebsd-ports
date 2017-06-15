--- iflib/clibrary.h.orig	1993-09-11 15:16:11 UTC
+++ iflib/clibrary.h
@@ -102,9 +102,11 @@ extern unsigned long	inet_addr();
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
@@ -121,8 +123,10 @@ extern int	alarm();
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
