--- texk/ttf2pk2/pklib.c.orig	2013-07-01 08:05:31.000000000 +0000
+++ texk/ttf2pk2/pklib.c	2020-08-19 13:23:37.764387000 +0000
@@ -64,8 +64,8 @@
 #define PK_POST (char)245
 #define PK_NOP  (char)246
 
-int dpi;
+extern int dpi;

 FILE *pk_file;
 
 
