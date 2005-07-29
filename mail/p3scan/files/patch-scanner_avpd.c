--- scanner_avpd.c.orig      Wed Jan  5 20:53:04 2005
+++ scanner_avpd.c   Tue Jul 26 12:44:34 2005
@@ -39,12 +39,12 @@
 #include <time.h>
 #include <sys/time.h>
 #include <errno.h>
-#include <malloc.h>
 #include <sys/un.h>
 #include <sys/socket.h>
 #include <stdarg.h>
 #include <dirent.h>
 #include <ctype.h>
+#include <netinet/in.h>
 
 #include "p3scan.h"
 
