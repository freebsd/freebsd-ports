--- src/cfgparser_orig.c	Sun Nov 12 13:40:35 2006
+++ src/cfgparser.c	Mon Dec 11 09:58:17 2006
@@ -38,6 +38,50 @@
 
 #define USHARE_DIR_DELIM ","
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+char *strndup(const char *s, size_t n) {
+  size_t len;
+  char *sdup;
+  if(!s)
+    return NULL;
+  len = strlen(s);
+  len = (n < len ? n : len);
+  sdup = (char *)malloc(len + 1);
+  if(sdup) {
+    memcpy(sdup, s, len);
+    sdup[len] = '\0';
+  }
+  return sdup;
+}
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
+#endif
+
 static bool
 ignore_line (const char *line)
 {
