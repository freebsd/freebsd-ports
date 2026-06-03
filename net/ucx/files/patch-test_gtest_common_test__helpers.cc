--- test/gtest/common/test_helpers.cc.orig	2026-02-04 09:52:46 UTC
+++ test/gtest/common/test_helpers.cc
@@ -13,6 +13,10 @@
 #include <ucs/config/global_opts.h>
 #include <ucs/config/parser.h>
 
+#include <pthread.h>
+#include <signal.h>
+#include <sys/wait.h>
+
 #include <set>
 
 extern "C" {
