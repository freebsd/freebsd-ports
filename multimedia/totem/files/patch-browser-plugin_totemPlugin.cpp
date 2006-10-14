--- browser-plugin/totemPlugin.cpp.orig	Mon Aug 14 17:01:14 2006
+++ browser-plugin/totemPlugin.cpp	Mon Aug 14 17:01:24 2006
@@ -27,6 +27,7 @@
 #include <stdint.h>
 #include <unistd.h>
 #include <fcntl.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <sys/poll.h>
 #include <string.h>
