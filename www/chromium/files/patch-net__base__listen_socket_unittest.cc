--- ./net/base/listen_socket_unittest.cc.orig	2010-12-16 02:11:31.000000000 +0100
+++ ./net/base/listen_socket_unittest.cc	2010-12-20 20:15:08.000000000 +0100
@@ -6,6 +6,9 @@
 
 #include <fcntl.h>
 #include <sys/types.h>
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
 
 #include "base/eintr_wrapper.h"
 #include "net/base/net_util.h"
