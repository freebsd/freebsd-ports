--- mojo/core/channel.cc.orig	2026-03-13 06:02:14 UTC
+++ mojo/core/channel.cc
@@ -74,7 +74,11 @@ const size_t kMaxAttachedHandles = 64;
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
@@ -267,7 +271,7 @@ bool ShouldRecordSubsampledHistograms() {
 }  // namespace
 
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(FUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION))
 
 namespace {
 
@@ -1313,7 +1317,7 @@ bool Channel::OnControlMessage(Message::MessageType me
 }
 
 // Currently only CrOs, Linux, and Android support upgrades.
-#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID))
+#if !(BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 // static
 MOJO_SYSTEM_IMPL_EXPORT bool Channel::SupportsChannelUpgrade() {
   return false;
