--- scanner_trophie.c.orig   Wed Jan  5 20:53:04 2005
+++ scanner_trophie.c        Tue Jul 26 12:44:51 2005
@@ -37,11 +37,11 @@
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <errno.h>
-#include <malloc.h>
 #include <sys/un.h>
 #include <sys/socket.h>
 #include <stdarg.h>
 #include <ctype.h>
+#include <netinet/in.h>

 #include "p3scan.h"
