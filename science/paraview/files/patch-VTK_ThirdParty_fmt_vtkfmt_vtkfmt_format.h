--- VTK/ThirdParty/fmt/vtkfmt/vtkfmt/format.h.orig	2026-05-22 16:18:17 UTC
+++ VTK/ThirdParty/fmt/vtkfmt/vtkfmt/format.h
@@ -52,6 +52,7 @@
 #  include <cmath>    // std::signbit
 #  include <cstddef>  // std::byte
 #  include <cstdint>  // uint32_t
+#  include <cstdlib>  // malloc/free
 #  include <cstring>  // std::memcpy
 #  include <limits>   // std::numeric_limits
 #  include <new>      // std::bad_alloc
