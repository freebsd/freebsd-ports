--- utils/readdb.c.orig	2016-03-25 20:56:46 UTC
+++ utils/readdb.c
@@ -9,7 +9,7 @@ char *id="\n\n\n\n\n-CW was here-\n\n\n\
 #include <stdio.h>
 #include <memory.h>
 #include <time.h>
-int main(unsigned int argc, char **argv)
+int main(int argc, char **argv)
 {
  unsigned long fsize, fcount, ccount, offset, offset2, i;
  unsigned char *db;
