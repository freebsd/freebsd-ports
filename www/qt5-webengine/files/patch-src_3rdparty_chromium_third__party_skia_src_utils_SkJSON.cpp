--- src/3rdparty/chromium/third_party/skia/src/utils/SkJSON.cpp.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/utils/SkJSON.cpp
@@ -34,6 +34,10 @@ void Value::init_tagged(Tag t) {
 
 // Pointer values store a type (in the upper kTagBits bits) and a pointer.
 void Value::init_tagged_pointer(Tag t, void* p) {
+#if !defined(SK_CPU_LENDIAN)
+    // Check that kRecAlign is large enough to leave room for the tag
+    static_assert(sizeof(Value) > sizeof(uintptr_t) || !(kRecAlign & Value::kTagMask), "kRecAlign is not a multiple of kTagMask+1");
+#endif
     *this->cast<uintptr_t>() = reinterpret_cast<uintptr_t>(p);
 
     if (sizeof(Value) == sizeof(uintptr_t)) {
@@ -169,7 +173,7 @@ class FastString final : public Value { (private)
 #if defined(SK_CPU_LENDIAN)
         *s64 &= 0x00ffffffffffffffULL >> ((kMaxInlineStringSize - size) * 8);
 #else
-        static_assert(false, "Big-endian builds are not supported at this time.");
+        *s64 &= 0xffffffffffffff00ULL << ((kMaxInlineStringSize - size) * 8);
 #endif
     }
 };
