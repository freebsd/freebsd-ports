--- src/gnomeicu-client.c.orig Sun Sep 29 14:59:15 2002
+++ src/gnomeicu-client.c      Sun Sep 29 14:59:25 2002
@@ -17,9 +17,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
-#include <sys/types.h>
 #include <sys/un.h>
 #include <unistd.h>

