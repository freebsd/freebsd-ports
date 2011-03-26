--- tools.c.orig
+++ tools.c
@@ -1201,9 +1201,35 @@ cReadLine::~cReadLine()
   free(buffer);
 }
 
+#ifdef __FreeBSD__
+#if __FreeBSD_version > 800000
+#define HAVE_GETLINE
+#endif
+#else
+#define HAVE_GETLINE
+#endif
+
 char *cReadLine::Read(FILE *f)
 {
+#ifndef HAVE_GETLINE
+  size_t n;
+
+  if (!buffer) {
+    if (!(buffer = (char *)malloc(size = 4096)))
+      return NULL;
+    }
+  if (!fgets(buffer, size, f))
+    return NULL;
+  while ((n = strlen(buffer)) >= size - 1 && buffer[n - 1] != '\n') {
+    if (!(buffer = (char *)realloc(buffer, size * 2)))
+      return NULL;
+    size *= 2;
+    if (!fgets(buffer + n, size - n, f))
+      break;
+    }
+#else
   int n = getline(&buffer, &size, f);
+#endif
   if (n > 0) {
      n--;
      if (buffer[n] == '\n') {
