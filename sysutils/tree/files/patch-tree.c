--- tree.c.orig	Mon Aug 16 02:07:21 2004
+++ tree.c	Thu Oct 21 11:51:36 2004
@@ -189,7 +189,6 @@
 FILE *outfile;
 int *dirs, maxdirs;
 
-extern size_t MB_CUR_MAX;
 
 int main(int argc, char **argv)
 {
