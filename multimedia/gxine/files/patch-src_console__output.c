--- src/console_output.c.orig	2017-12-27 17:41:32 UTC
+++ src/console_output.c
@@ -45,6 +45,159 @@ static void console_push (const char *s, uint8_t e) {}
 #else
 /* defines & functions for gxine */
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version < 800067
+
+/* from src/contrib/cvs/lib/getline.h */
+#if defined (__GNUC__) || (defined (__STDC__) && __STDC__)
+#define __PROTO(args) args
+#else
+#define __PROTO(args) ()
+#endif  /* GCC.  */
+
+#define GETLINE_NO_LIMIT -1
+
+int
+  getline __PROTO ((char **_lineptr, size_t *_n, FILE *_stream));
+int
+  getline_safe __PROTO ((char **_lineptr, size_t *_n, FILE *_stream,
+                         int limit));
+int
+  getstr __PROTO ((char **_lineptr, size_t *_n, FILE *_stream,
+		   int _terminator, int _offset, int limit));
+
+/* getline.h */
+/* from src/contrib/cvs/lib/getline.c */
+
+#include <sys/types.h>
+#include <assert.h>
+#include <errno.h>
+
+#define MIN_CHUNK 64
+
+int
+getstr (lineptr, n, stream, terminator, offset, limit)
+     char **lineptr;
+     size_t *n;
+     FILE *stream;
+     int terminator;
+     int offset;
+     int limit;
+{
+  int nchars_avail;		/* Allocated but unused chars in *LINEPTR.  */
+  char *read_pos;		/* Where we're reading into *LINEPTR. */
+  int ret;
+
+  if (!lineptr || !n || !stream)
+    {
+      errno = EINVAL;
+      return -1;
+    }
+
+  if (!*lineptr)
+    {
+      *n = MIN_CHUNK;
+      *lineptr = malloc (*n);
+      if (!*lineptr)
+	{
+	  errno = ENOMEM;
+	  return -1;
+	}
+      *lineptr[0] = '\0';
+    }
+
+  nchars_avail = *n - offset;
+  read_pos = *lineptr + offset;
+
+  for (;;)
+    {
+      int save_errno;
+      register int c;
+
+      if (limit == 0)
+          break;
+      else
+      {
+          c = getc (stream);
+
+          /* If limit is negative, then we shouldn't pay attention to
+             it, so decrement only if positive. */
+          if (limit > 0)
+              limit--;
+      }
+
+      save_errno = errno;
+
+      /* We always want at least one char left in the buffer, since we
+	 always (unless we get an error while reading the first char)
+	 NUL-terminate the line buffer.  */
+
+      assert((*lineptr + *n) == (read_pos + nchars_avail));
+      if (nchars_avail < 2)
+	{
+	  if (*n > MIN_CHUNK)
+	    *n *= 2;
+	  else
+	    *n += MIN_CHUNK;
+
+	  nchars_avail = *n + *lineptr - read_pos;
+	  *lineptr = realloc (*lineptr, *n);
+	  if (!*lineptr)
+	    {
+	      errno = ENOMEM;
+	      return -1;
+	    }
+	  read_pos = *n - nchars_avail + *lineptr;
+	  assert((*lineptr + *n) == (read_pos + nchars_avail));
+	}
+
+      if (ferror (stream))
+	{
+	  /* Might like to return partial line, but there is no
+	     place for us to store errno.  And we don't want to just
+	     lose errno.  */
+	  errno = save_errno;
+	  return -1;
+	}
+
+      if (c == EOF)
+	{
+	  /* Return partial line, if any.  */
+	  if (read_pos == *lineptr)
+	    return -1;
+	  else
+	    break;
+	}
+
+      *read_pos++ = c;
+      nchars_avail--;
+
+      if (c == terminator)
+	/* Return the line.  */
+	break;
+    }
+
+  /* Done - NUL terminate and return the number of chars read.  */
+  *read_pos = '\0';
+
+  ret = read_pos - (*lineptr + offset);
+  return ret;
+}
+
+int
+getline (lineptr, n, stream)
+     char **lineptr;
+     size_t *n;
+     FILE *stream;
+{
+  return getstr (lineptr, n, stream, '\n', 0, GETLINE_NO_LIMIT);
+}
+
+/* getline.c */
+#endif /* __FreeBSD_version */
+#endif /* defined(__FreeBSD__) */
+
 # include <pthread.h>
 # include <string.h>
 # include "log_window.h"
