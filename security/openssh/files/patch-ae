--- sshlogin.c.orig	Sat Mar 24 17:43:27 2001
+++ sshlogin.c	Sat May 26 14:42:30 2001
@@ -41,7 +41,11 @@
 #include "includes.h"
 RCSID("$OpenBSD: sshlogin.c,v 1.2 2001/03/24 16:43:27 stevesk Exp $");
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#else
 #include <util.h>
+#endif /* __FreeBSD__ */
 #include <utmp.h>
 #include "sshlogin.h"
 #include "log.h"
