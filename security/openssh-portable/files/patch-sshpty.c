--- sshpty.c.orig	Wed Jun 26 01:21:42 2002
+++ sshpty.c	Fri Jun 28 07:09:38 2002
@@ -30,6 +30,9 @@
 #ifdef HAVE_PTY_H
 # include <pty.h>
 #endif
+#ifdef HAVE_LIBUTIL_H
+#include <libutil.h>
+#endif
 #if defined(HAVE_DEV_PTMX) && defined(HAVE_SYS_STROPTS_H)
 # include <sys/stropts.h>
 #endif
