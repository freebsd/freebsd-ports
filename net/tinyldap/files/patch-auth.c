--- auth.c.orig	Tue May 14 22:26:20 2002
+++ auth.c	Thu Feb 26 16:03:58 2004
@@ -1,3 +1,6 @@
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 #include <md5.h>
 #include "ldap.h"
 #include "auth.h"
