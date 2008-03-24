--- src/polkit/polkit-sysdeps.c.orig	2007-11-28 16:26:14.000000000 -0500
+++ src/polkit/polkit-sysdeps.c	2008-01-02 00:42:47.000000000 -0500
@@ -39,7 +39,6 @@
 #include <grp.h>
 #include <unistd.h>
 #include <errno.h>
-#include <sys/inotify.h>
 #include <syslog.h>
 
 #include "polkit-sysdeps.h"
@@ -82,7 +81,11 @@ polkit_sysdeps_get_start_time_for_pid (p
         start_time = 0;
         contents = NULL;
 
+#ifdef __FreeBSD__
+        filename = kit_strdup_printf ("/proc/%d/status", pid);
+#else
         filename = kit_strdup_printf ("/proc/%d/stat", pid);
+#endif
         if (filename == NULL) {
                 errno = ENOMEM;
                 goto out;
@@ -93,6 +96,35 @@ polkit_sysdeps_get_start_time_for_pid (p
                 goto out;
         }
 
+#ifdef __FreeBSD__
+        tokens = kit_strsplit (contents, ' ', &num_tokens);
+        if (tokens == NULL)
+                goto out;
+        if (num_tokens < 8) {
+                kit_strfreev (tokens);
+                goto out;
+        }
+
+        p = kit_strdup (tokens[7]);
+        kit_strfreev (tokens);
+
+        tokens = kit_strsplit (p, ',', &num_tokens);
+        if (tokens == NULL)
+                goto out;
+        if (num_tokens >= 1) {
+                start_time = strtoll (tokens[0], &endp, 10);
+                if (endp == tokens[0]) {
+                        kit_strfreev (tokens);
+                        goto out;
+                }
+        } else {
+                kit_strfreev (tokens);
+                goto out;
+        }
+
+        kit_strfreev (tokens);
+#else
+
         /* start time is the 19th token after the '(process name)' entry */
 
         p = strchr (contents, ')');
@@ -118,6 +150,7 @@ polkit_sysdeps_get_start_time_for_pid (p
         }
 
         kit_strfreev (tokens);
+#endif
 
 out:
         kit_free (filename);
@@ -153,7 +186,11 @@ polkit_sysdeps_get_exe_for_pid (pid_t pi
 
         ret = 0;
 
+#ifdef __FreeBSD__
+        snprintf (proc_name, sizeof (proc_name), "/proc/%d/file", pid);
+#else
         snprintf (proc_name, sizeof (proc_name), "/proc/%d/exe", pid);
+#endif
         ret = readlink (proc_name, out_buf, buf_size - 1);
         if (ret == -1) {
                 strncpy (out_buf, "(unknown)", buf_size);
@@ -166,6 +203,108 @@ out:
         return ret;
 }
 
+#ifndef HAVE_GETLINE
+/* Taken from GNU sed. */
+/* Read up to (and including) a '\n' from STREAM into *LINEPTR
+   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
+   NULL), pointing to *N characters of space.  It is realloc'd as
+   necessary.  Returns the number of characters read (not including the
+   null terminator), or -1 on error or EOF.  */
+
+ssize_t
+polkit_sysdeps_getline (char **lineptr, size_t *n, FILE *stream)
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
+polkit_sysdeps_getline (char **lineptr, size_t *n, FILE *stream)
+{
+        return getline (lineptr, n, stream);
+}
+#endif
+
+#ifndef HAVE_CLEARENV
+extern char **environ;
+int
+polkit_sysdeps_clearenv (void)
+{
+	if (environ != NULL) {
+        	environ[0] = NULL;
+	}
+        return 0;
+}
+#else
+int
+polkit_sysdeps_clearenv (void)
+{
+        return clearenv ();
+}
+#endif
+
 #ifdef POLKIT_BUILD_TESTS
 
 static polkit_bool_t
