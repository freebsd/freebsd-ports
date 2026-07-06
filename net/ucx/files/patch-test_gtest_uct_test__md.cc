--- test/gtest/uct/test_md.cc.orig	2026-05-07 22:05:14 UTC
+++ test/gtest/uct/test_md.cc
@@ -21,6 +21,7 @@ extern "C" {
 #include <uct/ib/base/ib_md.h>
 #endif
 }
+#include <sys/wait.h>
 #include <sys/resource.h>
 #include <net/if_arp.h>
 #include <ifaddrs.h>
