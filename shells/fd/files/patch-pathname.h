--- pathname.h.orig	Wed Jun  9 00:00:00 2004
+++ pathname.h	Sun Jun 13 01:47:14 2004
@@ -129,6 +129,7 @@
 #define	EA_NOEVALQ	0010
 #define	EA_STRIPQLATER	0020
 #define	EA_NOUNIQDELIM	0040
+#define	EA_EOLMETA	0100
 
 #ifdef	NOUID_T
 typedef u_short	uid_t;
