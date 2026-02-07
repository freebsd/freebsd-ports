--- core/Common/3dParty/v8_89/v8/src/base/macros.h.orig	2021-04-12 21:00:33 UTC
+++ core/Common/3dParty/v8_89/v8/src/base/macros.h
@@ -203,7 +203,8 @@
 // base::is_trivially_copyable will differ for these cases.
 template <typename T>
 struct is_trivially_copyable {
-#if V8_CC_MSVC
+#if V8_CC_MSVC || (__GNUC__ == 12 && __GNUC_MINOR__ <= 2) || \
+    (defined(__clang__) && __clang_major__ <= 17)
   // Unfortunately, MSVC 2015 is broken in that std::is_trivially_copyable can
   // be false even though it should be true according to the standard.
   // (status at 2018-02-26, observed on the msvc waterfall bot).
