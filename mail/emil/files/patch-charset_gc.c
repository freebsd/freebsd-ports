--- charset/gc.c.orig	2011-07-25 20:24:02.000000000 +0200
+++ charset/gc.c	2011-07-25 20:24:04.000000000 +0200
@@ -256,7 +256,7 @@ char *file, *mode;
 }
 
 
-void
+int
   main (argc, argv) 
 int argc; char **argv; {
   
