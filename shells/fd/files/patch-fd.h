--- fd.h.orig	Wed Jun 23 00:00:00 2004
+++ fd.h	Fri Jun 25 01:18:25 2004
@@ -159,11 +159,11 @@
  ****************************************************************/
 #define	MAXBINDTABLE	256
 #define	MAXMACROTABLE	64
-#define	MAXLAUNCHTABLE	32
-#define	MAXARCHIVETABLE	16
+#define	MAXLAUNCHTABLE	64
+#define	MAXARCHIVETABLE	32
 #define	MAXALIASTABLE	256
 #define	MAXFUNCTABLE	32
-#define	MAXFUNCLINES	16
+#define	MAXFUNCLINES	32
 #if	MSDOS
 #define	MAXCOMMSTR	(128 - 2)
 #endif
@@ -171,7 +171,7 @@
 #define	MAXSTACK	5
 #define	MAXWINDOWS	2
 #define	MAXHISTNO	MAXTYPE(short)
-#define	MAXINVOKEARGS	1
+#define	MAXINVOKEARGS	MAXWINDOWS
 
 #ifdef	_NOSPLITWIN
 #undef	MAXWINDOWS
