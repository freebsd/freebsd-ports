--- fd.h.orig	Tue Aug 10 00:00:00 2004
+++ fd.h	Fri Aug 20 10:01:22 2004
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
