--- fd.h.orig	2019-07-26 15:00:00 UTC
+++ fd.h
@@ -215,11 +215,11 @@ extern char *_mtrace_file;
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
@@ -408,7 +408,7 @@ extern char *_mtrace_file;
 #define	TC_USED			(TC_TOTAL + TW_TOTAL + TD_TOTAL + TW_GAP)
 #define	TC_FREE			(TC_USED + TW_USED + TD_USED + TW_GAP)
 
-#define	WSIZE			9
+#define	WSIZE			10
 #define	WSIZE2			8
 #define	TWSIZE2			10
 #define	WDATE			8
