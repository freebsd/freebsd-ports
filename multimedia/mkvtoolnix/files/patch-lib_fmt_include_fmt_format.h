--- lib/fmt/include/fmt/format.h.orig	2026-01-02 12:35:10 UTC
+++ lib/fmt/include/fmt/format.h
@@ -44,6 +44,7 @@
 #  include <cmath>    // std::signbit
 #  include <cstddef>  // std::byte
 #  include <cstdint>  // uint32_t
+#  include <cstdlib>  // malloc/free
 #  include <cstring>  // std::memcpy
 #  include <limits>   // std::numeric_limits
 #  include <new>      // std::bad_alloc
