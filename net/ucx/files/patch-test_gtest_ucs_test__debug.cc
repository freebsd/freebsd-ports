--- test/gtest/ucs/test_debug.cc.orig	2026-02-04 09:52:47 UTC
+++ test/gtest/ucs/test_debug.cc
@@ -11,6 +11,7 @@ extern "C" {
 #include <ucs/sys/sys.h>
 }
 
+#include <libgen.h>
 #include <dlfcn.h>
 
 extern "C" {
@@ -24,7 +25,10 @@ std::string __basename(const std::string& path) {
 
 std::string __basename(const std::string& path) {
     char *p = strdup(path.c_str());
-    std::string bn(::basename(p));
+    /* basename() may modify its argument on some platforms */
+    char *path = strdup(p);
+    std::string bn(::basename(path));
+    free(path);
     free(p);
     return bn;
 }
