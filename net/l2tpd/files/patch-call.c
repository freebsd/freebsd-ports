
$FreeBSD$

--- call.c.orig	Sat Aug 10 03:47:25 2002
+++ call.c	Thu Oct 16 23:13:51 2003
@@ -14,9 +14,6 @@
 
 #include <stdio.h>
 #include <fcntl.h>
-#include <sys/socket.h>
-#include <netinet/in.h>
-#include <arpa/inet.h>
 #include <sys/wait.h>
 #include <stdlib.h>
 #include <string.h>
@@ -193,8 +190,8 @@
         }
     }
     /* I should never get here */
-    log (LOG_WARN, "%s: You should not see this message.  If you do, please
-		       enter a bug report at http://sourceforge.net/projects/l2tpd", __FUNCTION__);
+    log (LOG_WARN, "%s: You should not see this message.  If you do, please "
+		       "enter a bug report at http://sourceforge.net/projects/l2tpd", __FUNCTION__);
     return -EINVAL;
 }
 
