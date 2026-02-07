--- misc/ftp_funcs.c	2020-12-31 17:13:13.381267000 -0500
+++ misc/ftp_funcs.c	2020-12-31 17:15:17.095282000 -0500
@@ -20,6 +20,8 @@
 
 #include "network.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
