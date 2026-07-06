--- test/gtest/ucs/test_debug.cc.orig	2026-05-07 22:42:39 UTC
+++ test/gtest/ucs/test_debug.cc
@@ -11,6 +11,7 @@ extern "C" {
 #include <ucs/sys/sys.h>
 }
 
+#include <libgen.h>
 #include <dlfcn.h>
 
 extern "C" {
