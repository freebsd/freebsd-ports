--- sshpty.c.orig	Sun Mar  4 02:46:30 2001
+++ sshpty.c	Sat May 26 15:21:34 2001
@@ -14,7 +14,11 @@
 #include "includes.h"
 RCSID("$OpenBSD: sshpty.c,v 1.1 2001/03/04 01:46:30 djm Exp $");
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#else
 #include <util.h>
+#endif
 #include "sshpty.h"
 #include "log.h"
 
