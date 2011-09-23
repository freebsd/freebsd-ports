--- ../src/main.c.orig	2011-09-19 09:01:45.000000000 +0800
+++ ../src/main.c	2011-09-19 09:02:18.000000000 +0800
@@ -578,7 +578,7 @@ cleanup()
 	uucpunlock(n0);
 }
 
-void
+int
 main(argc, argv)
 	int argc;
 	char **argv;
