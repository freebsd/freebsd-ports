$FreeBSD$

--- src/wrappers.c.orig	Mon Mar 29 12:59:20 2004
+++ src/wrappers.c	Mon Mar 29 13:47:54 2004
@@ -42,6 +42,7 @@
 #if HAVE_POLL
 #include <sys/poll.h>
 #endif
+#include <limits.h>
 
 #include "wrappers.h"
 #include "cbuf.h"
@@ -486,7 +487,10 @@
          */
         if (!((errno == EWOULDBLOCK) ||
               (errno == ECONNABORTED) ||
-              (errno == EPROTO) || (errno == EINTR)))
+#ifdef __linux__
+              (errno == EPROTO) ||
+#endif
+              (errno == EINTR)))
             lsd_fatal_error(__FILE__, __LINE__, "accept");
     }
     return new;
@@ -639,8 +643,10 @@
     int n;
     char buf[MAX_REG_BUF];
 
+#ifdef __linux__
     /* Review: undocumented, is it needed? */
     re_syntax_options = RE_SYNTAX_POSIX_EXTENDED;
+#endif
     Strncpy(buf, string, MAX_REG_BUF);
     n = regexec(preg, buf, nmatch, pmatch, eflags);
     return n;
