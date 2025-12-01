--- tests/SimpleSessionLock.cpp.orig	2025-12-01 05:13:48 UTC
+++ tests/SimpleSessionLock.cpp
@@ -12,6 +12,7 @@
 #include <hyprutils/memory/SharedPtr.hpp>
 #include <hyprutils/memory/UniquePtr.hpp>
 
+#include <algorithm>
 #include <print>
 
 using namespace Hyprutils::Memory;
