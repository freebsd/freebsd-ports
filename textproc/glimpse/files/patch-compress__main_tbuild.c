--- ./compress/main_tbuild.c.orig	1999-11-03 20:40:10.000000000 +0000
+++ ./compress/main_tbuild.c	2014-01-27 21:40:18.000000000 +0000
@@ -25,7 +25,7 @@
 int
 main(argc, argv)
 	int	argc;
-	unsigned char	*argv[];
+	char	*argv[];
 {
 	char	comp_dir[MAX_LINE_LEN];
 	int	threshold, specialwords;
