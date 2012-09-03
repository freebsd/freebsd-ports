--- compress/main_tbuild.c.orig	2012-09-02 23:50:51.000000000 +0000
+++ compress/main_tbuild.c	2012-09-02 23:52:17.000000000 +0000
@@ -25,7 +25,7 @@
 int
 main(argc, argv)
 	int	argc;
-	unsigned char	*argv[];
+	char	*argv[];
 {
 	char	comp_dir[MAX_LINE_LEN];
 	int	threshold, specialwords;
