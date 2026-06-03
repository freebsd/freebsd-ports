--- third_party/fmt/include/fmt/format.h.orig	2026-03-23 18:40:46 UTC
+++ third_party/fmt/include/fmt/format.h
@@ -52,6 +52,7 @@
 #  include <cmath>    // std::signbit
 #  include <cstddef>  // std::byte
 #  include <cstdint>  // uint32_t
+#  include <cstdlib>  // malloc/free
 #  include <cstring>  // std::memcpy
 #  include <limits>   // std::numeric_limits
 #  include <new>      // std::bad_alloc
