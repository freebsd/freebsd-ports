--- base/posix/unix_domain_socket_linux_unittest.cc.orig	2017-04-19 19:06:28 UTC
+++ base/posix/unix_domain_socket_linux_unittest.cc
@@ -2,10 +2,15 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include "build/build_config.h"
+
 #include <stddef.h>
 #include <stdint.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#if defined(OS_BSD)
+#include <signal.h>
+#endif
 #include <unistd.h>
 
 #include "base/bind.h"
