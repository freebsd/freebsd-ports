--- arch/unix/fcgid_proc_unix.c.orig	Mon Jul 26 07:08:03 2004
+++ arch/unix/fcgid_proc_unix.c	Fri Aug 13 04:53:49 2004
@@ -1,3 +1,4 @@
+#include <sys/types.h>
 #include <sys/un.h>
 #include "httpd.h"
 #include "apr_thread_proc.h"
