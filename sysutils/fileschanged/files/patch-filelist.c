--- src/filelist.c.orig Mon Feb 23 02:17:30 2004
+++ src/filelist.c Wed May 19 18:30:04 2004
@@ -12,6 +12,30 @@
 #include "opts.h"
 #include "listdirs.h"
 extern struct arguments_t arguments;
+#if defined(__FreeBSD__)
+ssize_t getline(char **lineptr, size_t *n, FILE *stream)
+{
+ char *line;
+ size_t len;
+
+ line = fgetln(stream, &len);
+ if (!line)
+  return -1;
+ if (len >= *n) {
+  char *tmp;
+
+  /* XXX some realloc() implementations don't set errno */
+  tmp = realloc(*lineptr, len + 1);
+  if (!tmp)
+   return -1;
+  *lineptr = tmp;
+  *n = len + 1;
+ }
+ memcpy(*lineptr, line, len);
+ (*lineptr)[len] = 0;
+ return len;
+}
+#endif
 int for_every_filename(int (*for_every_file)(int (*)(void *, char *), void *list), int (*add_it_to_the)(void *list, char *filename), void *list)
 {
  for_every_file(add_it_to_the, list);
