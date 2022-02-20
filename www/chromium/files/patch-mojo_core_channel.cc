--- mojo/core/channel.cc.orig	2022-02-07 13:39:41 UTC
+++ mojo/core/channel.cc
@@ -62,7 +62,11 @@ const size_t kMaxUnusedReadBufferCapacity = 4096;
 // Fuchsia: The zx_channel_write() API supports up to 64 handles.
 const size_t kMaxAttachedHandles = 64;
 
+#if defined(__i386__) && defined(OS_FREEBSD)
+const size_t kChannelMessageAlignment = 4;
+#else
 static_assert(alignof(std::max_align_t) >= kChannelMessageAlignment, "");
+#endif
 Channel::AlignedBuffer MakeAlignedBuffer(size_t size) {
   // Generic allocators (such as malloc) return a pointer that is suitably
   // aligned for storing any type of object with a fundamental alignment
