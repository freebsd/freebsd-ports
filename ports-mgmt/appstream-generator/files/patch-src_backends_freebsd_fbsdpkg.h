--- src/backends/freebsd/fbsdpkg.h.orig	2025-09-25 21:14:13 UTC
+++ src/backends/freebsd/fbsdpkg.h
@@ -24,6 +24,7 @@
 #include <vector>
 #include <unordered_map>
 #include <memory>
+#include <mutex>
 #include <cstdint>
 #include <nlohmann/json.hpp>
 
