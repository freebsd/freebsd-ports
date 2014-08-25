--- ./net/base/address_tracker_linux_unittest.cc.orig	2014-08-20 21:02:28.000000000 +0200
+++ ./net/base/address_tracker_linux_unittest.cc	2014-08-22 15:06:26.000000000 +0200
@@ -4,7 +4,11 @@
 
 #include "net/base/address_tracker_linux.h"
 
+#if defined(__linux__)
 #include <linux/if.h>
+#else
+#include <net/if.h>
+#endif
 
 #include <vector>
 
