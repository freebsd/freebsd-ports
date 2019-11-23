--- src/3rdparty/chromium/third_party/skia/src/utils/SkJSON.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/utils/SkJSON.h
@@ -120,6 +120,7 @@ class alignas(8) Value { (protected)
          -- highest 3 bits reserved for type storage
 
      */
+#if defined(SK_CPU_LENDIAN)
     enum class Tag : uint8_t {
         // We picked kShortString == 0 so that tag 0x00 and stored max_size-size (7-7=0)
         // conveniently overlap the '\0' terminator, allowing us to store a 7 character
@@ -134,6 +135,22 @@ class alignas(8) Value { (protected)
         kObject                       = 0b11100000,  // ptr to external storage
     };
     static constexpr uint8_t kTagMask = 0b11100000;
+#else
+    enum class Tag : uint8_t {
+        // We picked kShortString == 0 so that tag 0x00 and stored max_size-size (7-7=0)
+        // conveniently overlap the '\0' terminator, allowing us to store a 7 character
+        // C string inline.
+        kShortString                  = 0b00000000,  // inline payload
+        kNull                         = 0b00000001,  // no payload
+        kBool                         = 0b00000010,  // inline payload
+        kInt                          = 0b00000011,  // inline payload
+        kFloat                        = 0b00000100,  // inline payload
+        kString                       = 0b00000101,  // ptr to external storage
+        kArray                        = 0b00000110,  // ptr to external storage
+        kObject                       = 0b00000111,  // ptr to external storage
+    };
+    static constexpr uint8_t kTagMask = 0b00000111;
+#endif
 
     void init_tagged(Tag);
     void init_tagged_pointer(Tag, void*);
@@ -192,14 +209,14 @@ class alignas(8) Value { (protected)
 
     uint8_t fData8[kValueSize];
 
-#if defined(SK_CPU_LENDIAN)
     static constexpr size_t kTagOffset = kValueSize - 1;
 
+#if defined(SK_CPU_LENDIAN)
     static constexpr uintptr_t kTagPointerMask =
             ~(static_cast<uintptr_t>(kTagMask) << ((sizeof(uintptr_t) - 1) * 8));
 #else
-    // The current value layout assumes LE and will take some tweaking for BE.
-    static_assert(false, "Big-endian builds are not supported at this time.");
+    static constexpr uintptr_t kTagPointerMask =
+            ~static_cast<uintptr_t>(kTagMask);
 #endif
 };
 
