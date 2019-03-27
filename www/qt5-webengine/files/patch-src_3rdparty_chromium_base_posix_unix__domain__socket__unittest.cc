--- src/3rdparty/chromium/base/posix/unix_domain_socket_unittest.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/posix/unix_domain_socket_unittest.cc
@@ -8,6 +8,9 @@
 #include <stdint.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/bind.h"
