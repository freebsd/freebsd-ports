--- net/base/address_tracker_linux_unittest.cc.orig	2014-10-10 08:54:16 UTC
+++ net/base/address_tracker_linux_unittest.cc
@@ -5,7 +5,11 @@
 #include "base/memory/scoped_ptr.h"
 #include "net/base/address_tracker_linux.h"
 
+#if defined(__linux__)
 #include <linux/if.h>
+#else
+#include <net/if.h>
+#endif
 
 #include <vector>
 
