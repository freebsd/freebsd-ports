--- xd.c.orig	1996-08-27 02:23:22.000000000 +0900
+++ xd.c	2012-10-24 05:56:31.000000000 +0900
@@ -392,7 +392,7 @@
  *
  */
 #define ISFILE(str) (*(str) != '-' || *((str) + 1) == '\0')
-void
+int
 main(int argc, char *argv[])
 {
 	int i, nf = 0, show_usage = FALSE, result;
