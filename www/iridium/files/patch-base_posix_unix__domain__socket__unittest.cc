--- base/posix/unix_domain_socket_unittest.cc.orig	2017-12-23 20:50:07.237565000 +0100
+++ base/posix/unix_domain_socket_unittest.cc	2017-12-23 20:51:05.651558000 +0100
@@ -8,6 +8,9 @@
 #include <stdint.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/bind.h"
