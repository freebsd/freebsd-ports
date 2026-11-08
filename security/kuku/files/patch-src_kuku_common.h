--- src/kuku/common.h.orig	2026-09-08 22:03:06 UTC
+++ src/kuku/common.h
@@ -20,30 +20,28 @@ namespace kuku
     */
     using item_type = std::array<unsigned char, 16>;
 
-    // Kuku's table layout is defined only for LITTLE-ENDIAN targets.
+    // Kuku's table layout is defined in terms of LITTLE-ENDIAN byte order, independently of
+    // the target's native byte order.
     //
-    // An item is 16 raw bytes, and those raw bytes are what BLAKE2xb hashes. Several places
-    // reinterpret them as integers using the native byte order: the word accessors below,
-    // increment_item, and HashFunc, which lets BLAKE2xb write its output directly into an
-    // array of location_type. On a big-endian target each of those reinterpretations yields
-    // different values, so the derived location functions - and hence the table layout -
-    // differ from a little-endian peer's.
+    // An item is 16 raw bytes, and those raw bytes are what BLAKE2xb hashes. Two places
+    // interpret bytes as integers: the word accessors below (on which increment_item is
+    // built), and HashFunc, which lets BLAKE2xb write its output directly into an array of
+    // location_type. Both read and write those integers in little-endian byte order, so the
+    // derived location functions - and hence the table layout - are the same on every
+    // target. This matters because Kuku's consumers are two-party protocols that must agree
+    // on where items live, and the two parties need not share a byte order.
     //
-    // The failure mode is what makes this worth a hard error. A big-endian build would not
-    // crash or produce a visibly wrong answer: it would compile, pass every test, and simply
-    // disagree with a little-endian peer about where items live. For a library whose
-    // consumers are two-party protocols that must agree on placement, a silent divergence is
-    // the worst available outcome, so the assumption fails loudly at compile time instead.
+    // On a little-endian target the conversions are the identity, and the accessors reduce
+    // to a single std::memcpy; that fast path is selected here. Every other target - a
+    // big-endian one, or a compiler that exposes no byte-order macro - takes a portable
+    // byte-by-byte path that is correct whatever the native byte order is. Correctness
+    // therefore never depends on this detection being right; only speed does.
     //
     // MSVC defines no __BYTE_ORDER__, but every architecture it targets - x86, x64, ARM,
-    // ARM64 - is little-endian, so there is nothing to check there. Compilers defining
-    // neither macro fall through to the configure-time check in CMakeLists.txt.
-#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__)
-    static_assert(
-        __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__,
-        "Kuku's table layout is defined only for little-endian targets. On a big-endian "
-        "target Kuku would build and pass its tests while computing a different table layout "
-        "from its little-endian peers.");
+    // ARM64 - is little-endian.
+#if defined(_MSC_VER) || \
+    (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__))
+#define KUKU_NATIVE_LITTLE_ENDIAN
 #endif
 
     /**
@@ -144,28 +142,57 @@ namespace kuku
     }
 
     /**
-    Returns the low 64-bit word of the item.
+    Reads a 64-bit word stored in little-endian byte order. See the note on byte order above.
 
-    Uses std::memcpy to avoid strict-aliasing/alignment UB: item_type is
-    std::array<unsigned char, 16> with alignment 1, so reinterpret_cast<uint64_t*>
+    On a little-endian target this is a std::memcpy, which avoids strict-aliasing/alignment
+    UB: item_type is std::array<unsigned char, 16> with alignment 1, so reinterpret_cast<uint64_t*>
     on item.data() can be misaligned on strict-alignment targets (e.g., some ARM).
     */
-    inline std::uint64_t get_low_word(const item_type &item) noexcept
+    inline std::uint64_t load_word(const unsigned char *in) noexcept
     {
+#if defined(KUKU_NATIVE_LITTLE_ENDIAN)
         std::uint64_t value{};
-        std::memcpy(&value, item.data(), sizeof(value));
+        std::memcpy(&value, in, sizeof(value));
         return value;
+#else
+        std::uint64_t value = 0;
+        for (std::size_t i = 0; i < sizeof(value); i++)
+        {
+            value |= static_cast<std::uint64_t>(in[i]) << (8U * i);
+        }
+        return value;
+#endif
     }
 
     /**
-    Returns the high 64-bit word of the item. See get_low_word for the rationale
-    behind the std::memcpy-based implementation.
+    Stores a 64-bit word in little-endian byte order. See load_word.
     */
+    inline void store_word(std::uint64_t value, unsigned char *out) noexcept
+    {
+#if defined(KUKU_NATIVE_LITTLE_ENDIAN)
+        std::memcpy(out, &value, sizeof(value));
+#else
+        for (std::size_t i = 0; i < sizeof(value); i++)
+        {
+            out[i] = static_cast<unsigned char>(value >> (8U * i));
+        }
+#endif
+    }
+
+    /**
+    Returns the low 64-bit word of the item.
+    */
+    inline std::uint64_t get_low_word(const item_type &item) noexcept
+    {
+        return load_word(item.data());
+    }
+
+    /**
+    Returns the high 64-bit word of the item.
+    */
     inline std::uint64_t get_high_word(const item_type &item) noexcept
     {
-        std::uint64_t value{};
-        std::memcpy(&value, item.data() + bytes_per_uint64, sizeof(value));
-        return value;
+        return load_word(item.data() + bytes_per_uint64);
     }
 
     /**
@@ -173,7 +200,7 @@ namespace kuku
     */
     inline void set_low_word(std::uint64_t value, item_type &destination) noexcept
     {
-        std::memcpy(destination.data(), &value, sizeof(value));
+        store_word(value, destination.data());
     }
 
     /**
@@ -181,7 +208,7 @@ namespace kuku
     */
     inline void set_high_word(std::uint64_t value, item_type &destination) noexcept
     {
-        std::memcpy(destination.data() + bytes_per_uint64, &value, sizeof(value));
+        store_word(value, destination.data() + bytes_per_uint64);
     }
 
     /**
