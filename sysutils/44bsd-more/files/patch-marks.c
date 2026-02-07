--- marks.c.orig	2011-09-08 01:18:08.000000000 +0800
+++ marks.c	2011-09-08 01:18:34.000000000 +0800
@@ -129,6 +129,7 @@ badmark(c)
 /*
  * Set a bookmark.
  */
+void
 setmark(c)
 	int c;  /* user identifier for bookmark to set */
 {
@@ -318,6 +319,7 @@ fprintf_error:
 /*
  * Go to a previously set mark.
  */
+void
 gomark(c)
 	int c;
 {
