--- test/gtest/common/test_helpers.cc.orig	2026-05-06 13:47:14 UTC
+++ test/gtest/common/test_helpers.cc
@@ -13,6 +13,11 @@
 #include <ucs/config/global_opts.h>
 #include <ucs/config/parser.h>
 
+#include <pthread.h>
+#include <signal.h>
+#include <sys/wait.h>
+#include <netinet/in.h>
+
 #include <set>
 
 extern "C" {
@@ -513,7 +518,9 @@ out_close:
     }
 
 out_close:
-    closedir(dir);
+    if (dir != NULL) {
+        closedir(dir);
+    }
     return result;
 }
 
