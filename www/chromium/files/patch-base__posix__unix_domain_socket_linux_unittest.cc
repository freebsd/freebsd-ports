--- base/posix/unix_domain_socket_linux_unittest.cc.orig	2013-08-19 23:12:24.000000000 +0300
+++ base/posix/unix_domain_socket_linux_unittest.cc	2013-08-19 23:16:20.000000000 +0300
@@ -4,6 +4,9 @@
 
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/bind.h"
