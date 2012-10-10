--- Wrapping/vtkParsePreprocess.c.orig	2012-09-10 16:13:54.000000000 +0200
+++ Wrapping/vtkParsePreprocess.c	2012-09-10 16:14:03.000000000 +0200
@@ -33,6 +33,9 @@
 
 #define PREPROC_DEBUG 0
 
+/** Block size for reading files */
+#define FILE_BUFFER_SIZE 8192
+
 /** Preprocessor tokens. */
 enum _preproc_token_t
 {
@@ -1787,10 +1790,10 @@
   PreprocessInfo *info, const char *filename, int system_first)
 {
   char *tbuf;
-  size_t tbuflen = 8192;
+  size_t tbuflen = FILE_BUFFER_SIZE;
   char *line;
   size_t linelen = 80;
-  size_t i, j, n;
+  size_t i, j, n, r;
   int in_comment = 0;
   int in_quote = 0;
   int result = VTK_PARSE_OK;
@@ -1849,29 +1852,48 @@
   info->IsExternal = 1;
   info->FileName = path;
 
-  tbuf = (char *)malloc(tbuflen);
+  tbuf = (char *)malloc(tbuflen+4);
   line = (char *)malloc(linelen);
 
   /* the buffer must hold a whole line for it to be processed */
   j = 0;
   i = 0;
   n = 0;
+  r = 0;
 
   do
     {
-    if (i == n)
+    if (i >= n)
       {
+      /* recycle unused lookahead chars */
+      if (r)
+        {
+        r = n + 2 - i;
+        if (r == 2)
+          {
+          tbuf[0] = tbuf[tbuflen-2];
+          tbuf[1] = tbuf[tbuflen-1];
+          }
+        else if (r == 1)
+          {
+          tbuf[0] = tbuf[tbuflen-1];
+          }
+        }
+
       /* read the next chunk of the file */
       i = 0;
       if (feof(fp))
         {
-        n = 0;
+        /* still have the lookahead chars left */
+        n = r;
+        r = 0;
         }
       else
         {
+        /* fill the remainder of the buffer */
         errno = 0;
-        i = 0;
-        while ((n = fread(tbuf, 1, tbuflen, fp)) == 0 && ferror(fp))
+        tbuflen = r + FILE_BUFFER_SIZE;
+        while ((n = fread(&tbuf[r], 1, tbuflen-r, fp)) == 0 && ferror(fp))
           {
           if (errno != EINTR)
             {
@@ -1884,6 +1906,22 @@
           errno = 0;
           clearerr(fp);
           }
+
+        if (n + r < tbuflen)
+          {
+          /* this only occurs if the final fread does not fill the buffer */
+          n += r;
+          r = 0;
+          }
+        else
+          {
+          /* set a lookahead reserve of two chars */
+          n -= (2 - r);
+          r = 2;
+          }
+
+        /* guard against lookahead past last char in file */
+        tbuf[n + r] = '\0';
         }
       }
 
@@ -1891,7 +1929,7 @@
     while (i < n)
       {
       /* expand line buffer as necessary */
-      if (j+4 > linelen)
+      while (j+4 > linelen)
         {
         linelen *= 2;
         line = (char *)realloc(line, linelen);
@@ -1917,7 +1955,7 @@
           line[j++] = tbuf[i++];
           in_quote = 0;
           }
-        else if (tbuf[i] == '\\' && tbuf[i] == '\"')
+        else if (tbuf[i] == '\\' && tbuf[i+1] == '\"')
           {
           line[j++] = tbuf[i++];
           line[j++] = tbuf[i++];
@@ -1927,7 +1965,7 @@
           line[j++] = tbuf[i++];
           }
         }
-      else if (tbuf[i] == '/' && tbuf[i] == '*')
+      else if (tbuf[i] == '/' && tbuf[i+1] == '*')
         {
         line[j++] = tbuf[i++];
         line[j++] = tbuf[i++];
