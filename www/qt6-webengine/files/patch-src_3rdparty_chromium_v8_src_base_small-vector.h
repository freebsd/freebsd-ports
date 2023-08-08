--- src/3rdparty/chromium/v8/src/base/small-vector.h.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/v8/src/base/small-vector.h
@@ -22,7 +22,7 @@ class SmallVector {
 class SmallVector {
   // Currently only support trivially copyable and trivially destructible data
   // types, as it uses memcpy to copy elements and never calls destructors.
-  ASSERT_TRIVIALLY_COPYABLE(T);
+  // XXX FREEBSD ASSERT_TRIVIALLY_COPYABLE(T);
   static_assert(std::is_trivially_destructible<T>::value);
 
  public:
