--- src/core/Backend.cpp.orig	2025-11-12 08:07:15 UTC
+++ src/core/Backend.cpp
@@ -19,6 +19,7 @@
 #include <sys/poll.h>
 
 #include <print>
+#include <unistd.h>
 
 using namespace Hyprtoolkit;
 using namespace Hyprutils::Memory;
