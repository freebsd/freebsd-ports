--- net/base/network_interfaces_posix.cc.orig	2021-04-14 18:41:06 UTC
+++ net/base/network_interfaces_posix.cc
@@ -4,8 +4,14 @@
 
 #include "net/base/network_interfaces_posix.h"
 
+#include "build/build_config.h"
+
 #include <netinet/in.h>
 #include <sys/types.h>
+
+#if defined(OS_BSD)
+#include <sys/socket.h>
+#endif
 
 #include <memory>
 #include <set>
