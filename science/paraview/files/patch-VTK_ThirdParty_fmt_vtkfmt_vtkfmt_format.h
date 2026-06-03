--- VTK/ThirdParty/fmt/vtkfmt/vtkfmt/format.h.orig	2025-09-25 09:24:50 UTC
+++ VTK/ThirdParty/fmt/vtkfmt/vtkfmt/format.h
@@ -44,6 +44,7 @@
 #  include <cmath>    // std::signbit
 #  include <cstddef>  // std::byte
 #  include <cstdint>  // uint32_t
+#  include <cstdlib>  // malloc/free
 #  include <cstring>  // std::memcpy
 #  include <limits>   // std::numeric_limits
 #  include <new>      // std::bad_alloc
