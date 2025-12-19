--- src/3rdparty/chromium/mojo/core/channel.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/mojo/core/channel.cc
@@ -83,7 +83,11 @@ const size_t kMaxAttachedHandles = 253;
 const size_t kMaxAttachedHandles = 253;
 #endif  // BUILDFLAG(IS_FUCHSIA)
 
+#if defined(__i386__) && defined(OS_FREEBSD)
+const size_t kChannelMessageAlignment = 4;
+#else
 static_assert(alignof(std::max_align_t) >= kChannelMessageAlignment, "");
+#endif
 Channel::AlignedBuffer MakeAlignedBuffer(size_t size) {
   // Generic allocators (such as malloc) return a pointer that is suitably
   // aligned for storing any type of object with a fundamental alignment
