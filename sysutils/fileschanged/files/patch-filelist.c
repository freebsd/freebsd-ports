--- src/filelist.c.orig	Wed Apr 19 21:42:28 2006
+++ src/filelist.c	Mon Jun  4 21:31:54 2007
@@ -4,7 +4,6 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <error.h>
 #include "gettext.h"
 #include <libgen.h>
 #include <unistd.h>
@@ -16,6 +15,31 @@
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
+
 /*
  * filelist.c:
  *   int filelist_populate (void *list_of_files_to_monitor);
@@ -74,7 +98,7 @@
     {
       fileptr = fopen (filename, "r");
       if (!fileptr)
-	error(1, 0, _("Error: couldn't open '%s'\n"), filename);
+	fprintf(stderr, _("Error: couldn't open '%s'\n"), filename);
     }
   while (getline (&line, &n, fileptr) > 0)
     {
