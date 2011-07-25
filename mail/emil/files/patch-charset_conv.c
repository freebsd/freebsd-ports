--- charset/conv.c.orig	2011-07-25 20:26:26.000000000 +0200
+++ charset/conv.c	2011-07-25 20:25:30.000000000 +0200
@@ -65,10 +65,10 @@ Char *b, *bm;
 }
 
 
-void
+int
 main (argc, argv)
 	int	 argc;
-	Char   **argv;
+	char   **argv;
 {
 	Char s ARRAY(SLEN), r ARRAY(SLEN), *opt=NULL, *o=r, c;
 	char dk ARRAY(3), us ARRAY(3);
