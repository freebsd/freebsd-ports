--- src/core/platforms/WaylandPlatform.cpp.orig	2025-11-12 08:07:51 UTC
+++ src/core/platforms/WaylandPlatform.cpp
@@ -15,6 +15,7 @@
 #include <cstring>
 #include <sys/mman.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 using namespace Hyprtoolkit;
 using namespace Hyprutils::Math;
