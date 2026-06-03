--- machine.h.orig	2019-07-26 15:00:00 UTC
+++ machine.h
@@ -594,25 +594,6 @@ typedef long	off_t;
 #define	USEINETATON
 #endif
 
-#if	defined (__FreeBSD__) && defined (__powerpc__)
-#define	BSD44
-#define	OSTYPE			"JCCBSD"
-#define	CODEEUC
-#define	TARUSESPACE
-#define	REGEXPLIB		"-lcompat"
-#define	DECLSIGLIST
-#define	DECLERRLIST
-#define	USELEAPCNT
-#define	USEMOUNTH
-#define	USEMNTINFO
-#define	USERE_COMP
-#define	USESETENV
-#define	ULONGIOCTL
-#define	USEMKTIME
-#define	SIGFNCINT
-#define	USEINETATON
-#endif
-
 #if	defined (__FreeBSD__) && !defined (OSTYPE) && !defined (__BOW__)
 #define	BSD44
 #define	OSTYPE			"FREEBSD"
@@ -1341,7 +1322,7 @@ typedef unsigned long		u_long;
 #define	CCCOMMAND		"cc"
 #endif
 #ifndef	EXTENDCCOPT
-#define	EXTENDCCOPT		"-O"
+#define	EXTENDCCOPT		""
 #endif
 #ifndef	TERMCAPLIB
 # ifdef	USETERMINFO
