--- stripstring.c.orig	Fri Sep  8 08:38:28 2006
+++ stripstring.c	Thu Sep 21 21:08:24 2006
@@ -417,7 +417,7 @@
 
 char do_strip_column(char *delimiter, int col_nr, char *in, char *strip_what)
 {
-	char changed = 0;;
+	char changed = 0;
 	char *p = in;
 	int del_len = strlen(delimiter);
 	int col_i;
