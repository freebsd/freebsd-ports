--- barrier/barrierd.c.orig	Sat Oct 18 14:05:14 2003
+++ barrier/barrierd.c	Sat Oct 18 14:05:29 2003
@@ -38,7 +38,7 @@
 #include <string.h>
 #include <strings.h>
 #include <syslog.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include "../common/sockcommon.h"
 
 #if !defined(lint) && defined(__NetBSD__)
