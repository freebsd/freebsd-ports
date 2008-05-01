--- src/kit/kit-lib.c.orig	2008-04-22 00:52:17.000000000 -0400
+++ src/kit/kit-lib.c	2008-04-22 01:15:38.000000000 -0400
@@ -0,0 +1,136 @@
+/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*- */
+/***************************************************************************
+ *
+ * kit-lib.c : General utilities
+ *
+ * Copyright (C) 2007 David Zeuthen, <david@fubar.dk>
+ *
+ * Permission is hereby granted, free of charge, to any person
+ * obtaining a copy of this software and associated documentation
+ * files (the "Software"), to deal in the Software without
+ * restriction, including without limitation the rights to use, copy,
+ * modify, merge, publish, distribute, sublicense, and/or sell copies
+ * of the Software, and to permit persons to whom the Software is
+ * furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice shall be
+ * included in all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
+ * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
+ * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
+ * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
+ * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
+ * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
+ * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
+ * DEALINGS IN THE SOFTWARE.
+ *
+ **************************************************************************/
+
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#define _GNU_SOURCE
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <errno.h>
+
+#include <kit/kit.h>
+#include "kit-test.h"
+
+#ifndef HAVE_GETLINE
+ssize_t
+kit_getline (char **lineptr, size_t *n, FILE *stream)
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
+#else
+ssize_t
+kit_getline (char **lineptr, size_t *n, FILE *f)
+{
+        return getline (lineptr, n, f);
+}
+#endif
+
+#ifndef HAVE_CLEARENV
+extern char **environ;
+
+int
+kit_clearenv (void)
+{
+        if (environ != NULL)
+                environ[0] = NULL;
+        return 0;
+}
+#else
+int
+kit_clearenv (void)
+{
+        return clearenv ();
+}
+#endif
