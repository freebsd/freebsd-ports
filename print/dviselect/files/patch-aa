--- dviselect.c.orig	1989-11-15 13:19:15.000000000 +0100
+++ dviselect.c	2012-11-30 14:56:42.000000000 +0100
@@ -122,7 +122,6 @@
 /* save some string space: we use this a lot */
 char	writeerr[] = "error writing DVI file";
 
-char	*malloc(), *realloc(), *sprintf();
 
 /*
  * lint gets rather confused with the current definitions of getc and putc,
@@ -136,6 +135,9 @@
 #define getc(f)   (*(f)->_ptr++)
 #endif
 
+void HandleDVIFile (void);
+void EndPage (void);
+
 /*
  * Return true iff the 10 \counts are one of the desired output pages.
  */
@@ -190,6 +192,7 @@
 /*
  * Start a page (process a DVI_BOP).
  */
+void
 BeginPage()
 {
 	register i32 *i;
@@ -243,6 +246,7 @@
 /*
  * End a page (process a DVI_EOP).
  */
+void
 EndPage()
 {
 	if (!ExpectEOP)
@@ -815,6 +819,7 @@
  * output DVI file. We also keep track of font changes, handle font
  * definitions, and perform some other housekeeping.
  */
+void
 HandleDVIFile()
 {
 	register int c, l;
