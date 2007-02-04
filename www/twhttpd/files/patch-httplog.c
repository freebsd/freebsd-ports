--- httplog.c.orig	Sat Dec  8 22:15:44 2001
+++ httplog.c	Sun Feb  4 20:10:16 2007
@@ -39,11 +39,13 @@
 
 #include <time.h>
 #include <stdio.h>
+#include <string.h>
 #include <syslog.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/time.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 
 #include "config.h"
 #include "structs.h"
@@ -151,4 +153,4 @@
             }
         }
     }
-}
\ No newline at end of file
+}
