--- sshpty.c.orig	Wed Jan 21 07:07:17 2004
+++ sshpty.c	Wed Feb 25 11:58:54 2004
@@ -17,6 +17,9 @@
 #ifdef HAVE_UTIL_H
 # include <util.h>
 #endif /* HAVE_UTIL_H */
+#ifdef HAVE_LIBUTIL_H
+#include <libutil.h>
+#endif
 
 #include "sshpty.h"
 #include "log.h"
