--- charset/conv.c.orig	1994-12-16 12:47:50 UTC
+++ charset/conv.c
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
