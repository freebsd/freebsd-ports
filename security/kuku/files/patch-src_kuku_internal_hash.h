--- src/kuku/internal/hash.h.orig	2026-09-08 22:03:06 UTC
+++ src/kuku/internal/hash.h
@@ -8,6 +8,7 @@
 #include <array>
 #include <cstddef>
 #include <cstdint>
+#include <cstring>
 #include <stdexcept>
 
 namespace kuku
@@ -23,6 +24,22 @@ namespace kuku
             {
                 throw std::runtime_error("blake2xb failed");
             }
+#if !defined(KUKU_NATIVE_LITTLE_ENDIAN)
+            // BLAKE2xb wrote its output into random_array_ as raw bytes. Reread each entry as a
+            // little-endian word, so that the tabulation table - and hence every location this
+            // function returns - matches a little-endian peer's. See the note on byte order in
+            // kuku/common.h.
+            for (location_type &entry : random_array_)
+            {
+                std::array<unsigned char, sizeof(location_type)> bytes{};
+                std::memcpy(bytes.data(), &entry, bytes.size());
+                entry = 0;
+                for (std::size_t i = 0; i < bytes.size(); i++)
+                {
+                    entry |= static_cast<location_type>(bytes[i]) << (8U * i);
+                }
+            }
+#endif
         }
 
         location_type operator()(item_type item) const noexcept
