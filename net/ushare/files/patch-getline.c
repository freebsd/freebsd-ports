--- src/getline.c.orig	Sat Dec 23 02:49:09 2006
+++ src/getline.c	Sat Dec 23 13:26:42 2006
@@ -0,0 +1,32 @@
+#include <sys/types.h>
+#include <stdio.h>
+#include <string.h>
+#include <stdlib.h>
+#include "getline.h"
+
+ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
+  static char line[256];
+  char *ptr;
+  unsigned int len;
+  if(lineptr == NULL || n == NULL) {
+    return -1;
+  }
+  if(ferror(stream))
+    return -1;
+  if(feof(stream))
+    return -1;
+  fgets(line,256,stream);
+  ptr = strchr(line,'\n');   
+  if(ptr)
+    *ptr = '\0';
+  len = strlen(line);
+  if((len+1) < 256) {
+    ptr = realloc(*lineptr, 256);
+    if(ptr == NULL)
+      return(-1);
+    *lineptr = ptr;
+    *n = 256;
+  }
+  strcpy(*lineptr,line); 
+  return(len);
+}
