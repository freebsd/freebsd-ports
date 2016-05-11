--- charset/gc.c.orig	1994-11-29 16:01:57 UTC
+++ charset/gc.c
@@ -256,7 +256,7 @@ char *file, *mode;
 }
 
 
-void
+int
   main (argc, argv) 
 int argc; char **argv; {
   
