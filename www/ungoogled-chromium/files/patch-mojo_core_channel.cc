--- mojo/core/channel.cc.orig	2025-09-10 13:22:16 UTC
+++ mojo/core/channel.cc
@@ -80,7 +80,11 @@ const size_t kMaxAttachedHandles = 64;
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
@@ -1162,7 +1166,7 @@ void Channel::LogHistogramForIPCMetrics(MessageType ty
 }
 
 // Currently only CrOs, Linux, and Android support upgrades.
-#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID))
+#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 // static
 MOJO_SYSTEM_IMPL_EXPORT bool Channel::SupportsChannelUpgrade() {
   return false;
