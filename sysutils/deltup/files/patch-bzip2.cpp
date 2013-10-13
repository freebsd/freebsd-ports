--- bzip2.cpp.orig	2007-03-25 01:59:24.000000000 +0300
+++ bzip2.cpp	2013-10-06 17:12:16.000000000 +0400
@@ -19,6 +19,8 @@
 #include "system.h"
 #include "tmpstore.h"
 #include "bzip2.h"
+#include <stdio.h>
+#include <stdlib.h>
 
 char *bzip2_compressor_name[MAX_BZIP2_COMPRESSORS] = {"0.9.0c", "1.0.2", "1.0.3", "1.0.4"};
 char *bzip2_name[MAX_BZIP2_COMPRESSORS] = {NULL, NULL, NULL, NULL};
@@ -31,14 +33,12 @@
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
@@ -56,8 +56,8 @@
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
