--- tt.h.orig	2008-07-12 06:05:22 UTC
+++ tt.h
@@ -98,7 +98,7 @@ struct tt {
 		/* ttflush() hook */
 	int (*tt_flush)();
 };
-struct tt tt;
+extern struct tt tt;
 
 /*
  * tt_padc is used by the compression routine.
@@ -120,8 +120,8 @@ extern struct tt_tab tt_tab[];
  * Clean interface to termcap routines.
  * Too may t's.
  */
-char tt_strings[1024];		/* string buffer */
-char *tt_strp;			/* pointer for it */
+extern char tt_strings[1024];		/* string buffer */
+extern char *tt_strp;			/* pointer for it */
 
 struct tt_str {
 	char *ts_str;
@@ -140,9 +140,9 @@ int tttputc();
  * These variables have different meanings from the ww_ob* variables.
  * But I'm too lazy to think up different names.
  */
-char *tt_ob;
-char *tt_obp;
-char *tt_obe;
+extern char *tt_ob;
+extern char *tt_obp;
+extern char *tt_obe;
 #define ttputc(c)	(tt_obp < tt_obe ? (*tt_obp++ = (c)) \
 				: (ttflush(), *tt_obp++ = (c)))
 
