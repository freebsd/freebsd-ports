--- net/base/address_tracker_linux_unittest.cc.orig	2016-05-11 19:02:24 UTC
+++ net/base/address_tracker_linux_unittest.cc
@@ -8,7 +8,11 @@
 #include "base/threading/simple_thread.h"
 #include "net/base/address_tracker_linux.h"
 
+#if defined(__linux__)
 #include <linux/if.h>
+#else
+#include <net/if.h>
+#endif
 
 #include <vector>
 
