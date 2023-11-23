--- src/3rdparty/chromium/v8/src/base/small-vector.h.orig	2022-10-25 08:25:05 UTC
+++ src/3rdparty/chromium/v8/src/base/small-vector.h
@@ -22,7 +22,7 @@ template <typename T, size_t kSize, typename Allocator
 class SmallVector {
   // Currently only support trivially copyable and trivially destructible data
   // types, as it uses memcpy to copy elements and never calls destructors.
-  ASSERT_TRIVIALLY_COPYABLE(T);
+  // XXX FREEBSD ASSERT_TRIVIALLY_COPYABLE(T);
   static_assert(std::is_trivially_destructible<T>::value);
 
  public:
