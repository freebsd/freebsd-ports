--- base/posix/unix_domain_socket_linux_unittest.cc.orig	2013-08-19 02:53:00.000000000 +0300
+++ base/posix/unix_domain_socket_linux_unittest.cc	2013-08-30 19:34:24.000000000 +0300
@@ -2,8 +2,13 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include "build/build_config.h"
+
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/bind.h"
