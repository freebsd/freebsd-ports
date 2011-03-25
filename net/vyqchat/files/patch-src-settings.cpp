--- src/settings.cpp.orig	2006-05-16 05:34:35.000000000 +0900
+++ src/settings.cpp	2011-03-16 13:57:41.000000000 +0900
@@ -12,14 +12,14 @@
 
 #include "global.h"
 #include "settings.h"
+#include <stdlib.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
-#include <net/if.h>
-#include <netinet/in.h>
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
-#include <stdlib.h>
+#include <net/if.h>
 
 Settings::Settings() /*{{{*/
 {
