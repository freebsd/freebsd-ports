--- bzip2.cpp.orig	2007-03-25 04:59:24.000000000 +0600
+++ bzip2.cpp		2008-03-09 11:19:55.000000000 +0500
@@ -19,6 +19,7 @@
 #include "system.h"
 #include "tmpstore.h"
 #include "bzip2.h"
+#include <stdio.h>

 char *bzip2_compressor_name[MAX_BZIP2_COMPRESSORS] = {"0.9.0c", "1.0.2", "1.0.3", "1.0.4"};
 char *bzip2_name[MAX_BZIP2_COMPRESSORS] = {NULL, NULL, NULL, NULL};
@@ -31,14 +32,12 @@
   system(command.c_str());

   FILE * fp;
-  char * line = NULL;
+  char line[2*CHAR_MAX];
   string fname;
-  size_t len = 0;
-  ssize_t read;
   fp = fopen(tempfile.c_str(), "r");
   if (fp == NULL)
        exit(EXIT_FAILURE);
-  while ((read = getline(&line, &len, fp)) != -1) {
+  while (fgets(line, 2*CHAR_MAX, fp)!=NULL) {
 //                 printf("Retrieved line of length %zu :\n", read);
 //                 printf("%s", line);
        char *v = strstr(line, "Version");
@@ -56,8 +55,8 @@
        }
        fname = line;
   }
-  if (line)
-       free(line);
+//  if (line)
+//      free(&line);
   if (verbose) {
     printf("found bzip2 compressors/decompressors:\n");
     for (int i = 0; i < MAX_BZIP2_COMPRESSORS; ++i) {
