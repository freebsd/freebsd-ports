--- Src/utils.c.orig	Wed Dec  4 19:39:01 2002
+++ Src/utils.c	Wed Dec  4 19:39:18 2002
@@ -1093,4 +1093,5 @@
  * is unique, for use as a temporary file.      */
  
+extern char *_mktemp(char *);
 /**/
 mod_export char *
