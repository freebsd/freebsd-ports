--- src/polkit-grant/polkit-grant.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit-grant/polkit-grant.c	2008-04-30 20:46:00.000000000 -0400
@@ -39,6 +39,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include <glib.h>
 #include "polkit-grant.h"
@@ -302,7 +303,7 @@ polkit_grant_io_func (PolKitGrant *polki
         g_return_if_fail (polkit_grant != NULL);
         g_return_if_fail (polkit_grant->helper_is_running);
 
-        while (getline (&line, &line_len, polkit_grant->child_stdout_f) != -1) {
+        while (kit_getline (&line, &line_len, polkit_grant->child_stdout_f) != -1) {
                 if (strlen (line) > 0 &&
                     line[strlen (line) - 1] == '\n')
                         line[strlen (line) - 1] = '\0';
@@ -419,6 +420,8 @@ polkit_grant_io_func (PolKitGrant *polki
 
         if (line != NULL)
                 free (line);
+
+        polkit_grant->func_remove_watch (polkit_grant, polkit_grant->io_watch_id);
 }
 
 /**
@@ -543,49 +546,6 @@ error:
         return FALSE;
 }
 
-#ifdef HAVE_SOLARIS
-#define BUFFER_LEN      256
-
-ssize_t getline (char **lineptr, size_t *n, FILE *f)
-{
-        char ch;
-        size_t m = 0;
-        ssize_t buf_len = 0;
-        char * buf = NULL;
-        char * p = NULL;
-
-
-        while ( (ch = getc(f)) !=EOF )
-        {
-                if (errno != 0)
-                        return -1;
-                if ( m++ >= buf_len )
-                {
-                        buf_len += BUFFER_LEN;
-                        buf = (char *) realloc(buf, buf_len + 1);
-                        if ( buf == NULL )
-                        {
-                                return -1;
-                        }
-                        p = buf + buf_len - BUFFER_LEN;
-                }
-                if ( ch == '\n' )
-                        break;
-                *p = ch;
-                p++;
-        }
-        if ( m == 0 )
-        {
-                return -1;
-        } else {
-                *p = '\0';
-                *lineptr = buf;
-                *n = m;
-                return m;
-        }
-}
-#endif
-
 #ifdef POLKIT_BUILD_TESTS
 
 static polkit_bool_t
