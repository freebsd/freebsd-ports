--- v8/src/base/macros.h.orig	2026-05-09 18:09:27 UTC
+++ v8/src/base/macros.h
@@ -224,7 +224,7 @@ V8_INLINE constexpr Dest bit_cast(Source const& source
 
 // Define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER macro.
 #if defined(__has_feature)
-#if __has_feature(undefined_behavior_sanitizer)
+#if __has_feature(undefined_behavior_sanitizer) && !defined(V8_OS_BSD)
 #define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER 1
 #endif
 #endif
