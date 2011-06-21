--- ./utils/readdb.c.orig	2011-06-21 15:44:50.000000000 +0200
+++ ./utils/readdb.c	2011-06-21 15:45:08.000000000 +0200
@@ -9,7 +9,7 @@
 #include <stdio.h>
 #include <memory.h>
 #include <time.h>
-int main(unsigned int argc, char **argv)
+int main(int argc, char **argv)
 {
  unsigned long fsize, fcount, ccount, offset, offset2, i;
  unsigned char *db;
