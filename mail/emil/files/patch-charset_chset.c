--- charset/chset.c.orig	1994-11-29 15:08:14 UTC
+++ charset/chset.c
@@ -42,7 +42,7 @@ int i;
 	return s;
 }
 
-void
+int
 main (argc, argv)
 	int	 argc;
 	char   **argv;
