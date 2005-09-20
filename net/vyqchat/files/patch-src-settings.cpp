--- src/settings.cpp	Mon Jul 18 21:54:08 2005
+++ src/settings.cpp	Sun Sep 18 21:20:55 2005
@@ -14,8 +14,9 @@
 #include "settings.h"
 #include <unistd.h>
 #include <sys/ioctl.h>
-#include <net/if.h>
 #include <sys/socket.h>
+#include <net/if.h>
+#include <netinet/in.h>
 #include <sys/types.h>
 #include <arpa/inet.h>
 #include <stdlib.h>
