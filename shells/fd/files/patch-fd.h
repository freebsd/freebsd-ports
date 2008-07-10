--- fd.h.orig	2008-04-19 00:00:00.000000000 +0900
+++ fd.h	2008-07-10 20:00:12.000000000 +0900
@@ -183,11 +183,11 @@
  ****************************************************************/
 #define	MAXBINDTABLE		256
 #define	MAXMACROTABLE		64
-#define	MAXLAUNCHTABLE		32
-#define	MAXARCHIVETABLE		16
+#define	MAXLAUNCHTABLE		64
+#define	MAXARCHIVETABLE		32
 #define	MAXALIASTABLE		256
 #define	MAXFUNCTABLE		32
-#define	MAXFUNCLINES		16
+#define	MAXFUNCLINES		32
 #if	MSDOS
 #define	MAXCOMMSTR		(128 - 2)
 #endif
