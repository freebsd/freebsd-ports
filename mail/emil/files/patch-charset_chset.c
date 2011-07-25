--- charset/chset.c.orig	2011-07-25 20:25:55.000000000 +0200
+++ charset/chset.c	2011-07-25 20:25:56.000000000 +0200
@@ -42,7 +42,7 @@ int i;
 	return s;
 }
 
-void
+int
 main (argc, argv)
 	int	 argc;
 	char   **argv;
