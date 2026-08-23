--- cargo-crates/v8-150.4.0/v8/src/base/macros.h.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/v8/src/base/macros.h
@@ -224,7 +224,7 @@ V8_INLINE constexpr Dest bit_cast(Source const& source
 
 // Define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER macro.
 #if defined(__has_feature)
-#if __has_feature(undefined_behavior_sanitizer)
+#if __has_feature(undefined_behavior_sanitizer) && !defined(V8_OS_BSD)
 #define V8_USE_UNDEFINED_BEHAVIOR_SANITIZER 1
 #endif
 #endif
