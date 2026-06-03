--- test/gtest/common/test_watchdog.cc.orig	2026-02-04 09:52:46 UTC
+++ test/gtest/common/test_watchdog.cc
@@ -9,6 +9,7 @@
 #endif
 
 #include <common/test.h>
+#include <signal.h>
 
 class test_watchdog : public ucs::test {
 public:
