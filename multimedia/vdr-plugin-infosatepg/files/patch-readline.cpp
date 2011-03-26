--- a/readline.cpp
+++ b/readline.cpp
@@ -10,6 +10,15 @@
 #include <stdio.h>
 #include "readline.h"
 
+#ifdef __FreeBSD__
+#include <string.h>
+#if __FreeBSD_version > 800000
+#define HAVE_GETLINE
+#endif
+#else
+#define HAVE_GETLINE
+#endif
+
 extern char *strcatrealloc(char *dest, const char *src);
 
 // --- cReadLineInfosatepg ---------------------------------------------------
@@ -36,7 +45,31 @@ char *cReadLineInfosatepg::Read(FILE *f,
   do
   {
     ext=false;
+#ifndef HAVE_GETLINE
+    size_t n;
+
+    if (!tempbuffer)
+    {
+      if (!(tempbuffer = (char *)malloc(tempsize = 4096)))
+        return NULL;
+    }
+    if (!fgets(tempbuffer, tempsize, f))
+    {
+      if (tempbuffer) free(tempbuffer);
+      return buffer;
+    }
+    while ((n = strlen(tempbuffer)) >= tempsize - 1 &&
+        tempbuffer[n - 1] != '\n')
+    {
+      if (!(tempbuffer = (char *)realloc(tempbuffer, tempsize * 2)))
+        return NULL;
+      tempsize *= 2;
+      if (!fgets(tempbuffer + n, tempsize - n, f))
+        break;
+    }
+#else
     int n = getline(&tempbuffer, &tempsize, f);
+#endif
     if (n > 0)
     {
       if (tempbuffer[n-1] == '\n')
