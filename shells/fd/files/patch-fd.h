--- fd.h.orig	Wed May 12 00:00:00 2004
+++ fd.h	Wed May 26 19:07:10 2004
@@ -171,11 +171,11 @@
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
