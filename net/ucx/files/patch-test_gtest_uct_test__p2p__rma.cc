--- test/gtest/uct/test_p2p_rma.cc.orig	2026-05-07 22:05:47 UTC
+++ test/gtest/uct/test_p2p_rma.cc
@@ -6,6 +6,7 @@
 
 #include "test_p2p_rma.h"
 
+#include <sys/wait.h>
 #include <functional>
 
 
