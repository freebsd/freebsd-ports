--- OpenSim/Common/Array.h.orig	2026-06-18 22:26:24 UTC
+++ OpenSim/Common/Array.h
@@ -35,7 +35,8 @@
 #include <initializer_list>
 #include <iostream>
 #include <iterator>
-#include <spdlog/fmt/bundled/ostream.h>
+// On FreeBSD fmt is not bundled with spdlog
+#include <fmt/ostream.h>
 #include <type_traits>
 #include <utility>
 #include <vector>
