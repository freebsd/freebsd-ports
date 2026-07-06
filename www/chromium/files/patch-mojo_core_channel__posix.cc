--- mojo/core/channel_posix.cc.orig	2026-07-01 06:24:19 UTC
+++ mojo/core/channel_posix.cc
@@ -622,6 +622,13 @@ void Channel::OfferChannelUpgrade() {
   }
   static_cast<ChannelLinux*>(this)->OfferSharedMemUpgrade();
 }
+#elif BUILDFLAG(IS_BSD)
+// static
+bool Channel::SupportsChannelUpgrade() {
+  return false;
+}
+void Channel::OfferChannelUpgrade() {
+}
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
 
