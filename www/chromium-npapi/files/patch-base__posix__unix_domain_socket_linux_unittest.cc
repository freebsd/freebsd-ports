--- ./base/posix/unix_domain_socket_linux_unittest.cc.orig	2014-04-30 22:41:41.000000000 +0200
+++ ./base/posix/unix_domain_socket_linux_unittest.cc	2014-05-04 14:38:46.000000000 +0200
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
