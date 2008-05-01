--- tools/polkit-auth.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ tools/polkit-auth.c	2008-04-22 01:24:55.000000000 -0400
@@ -37,7 +37,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
-#ifdef HAVE_SOLARIS
+#if defined(HAVE_SOLARIS) || defined(HAVE_FREEBSD)
 #include <sys/wait.h>
 #endif
 #include <pwd.h>
@@ -72,6 +72,77 @@ typedef struct {
         GMainLoop *loop;
 } UserData;
 
+#ifndef HAVE_GETLINE
+static ssize_t
+getline (char **lineptr, size_t *n, FILE *stream)
+{
+  char *line, *p;
+  long size, copy;
+
+  if (lineptr == NULL || n == NULL) {
+          errno = EINVAL;
+          return (ssize_t) -1;
+  }
+
+  if (ferror (stream))
+          return (ssize_t) -1;
+
+  /* Make sure we have a line buffer to start with.  */
+  if (*lineptr == NULL || *n < 2) /* !seen and no buf yet need 2 chars.  */ {
+#ifndef        MAX_CANON
+#define        MAX_CANON        256
+#endif
+          if (!*lineptr)
+                  line = (char *) malloc (MAX_CANON);
+          else
+                  line = (char *) realloc (*lineptr, MAX_CANON);
+          if (line == NULL)
+                  return (ssize_t) -1;
+          *lineptr = line;
+          *n = MAX_CANON;
+  }
+
+  line = *lineptr;
+  size = *n;
+
+  copy = size;
+  p = line;
+
+  while (1) {
+          long len;
+
+          while (--copy > 0) {
+                  int c = getc (stream);
+
+                  if (c == EOF)
+                          goto lose;
+                  else if ((*p++ = c) == '\n')
+                          goto win;
+          }
+
+          /* Need to enlarge the line buffer.  */
+          len = p - line;
+          size *= 2;
+          line = (char *) realloc (line, size);
+          if (line == NULL)
+                  goto lose;
+          *lineptr = line;
+          *n = size;
+          p = line + len;
+          copy = size - len;
+  }
+
+lose:
+  if (p == *lineptr)
+          return (ssize_t) -1;
+
+  /* Return a partial line since we got an error in the middle.  */
+win:
+  *p = '\0';
+  return p - *lineptr;
+}
+#endif
+
 static void
 conversation_type (PolKitGrant *polkit_grant, PolKitResult auth_type, void *user_data)
 {
