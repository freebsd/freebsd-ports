--- mojo/core/channel.h.orig	2021-04-28 14:44:22 UTC
+++ mojo/core/channel.h
@@ -22,7 +22,11 @@
 namespace mojo {
 namespace core {
 
+#if defined(__i386__) && defined(OS_FREEBSD)
+const size_t kChannelMessageAlignment = 4;
+#else
 const size_t kChannelMessageAlignment = 8;
+#endif
 
 constexpr bool IsAlignedForChannelMessage(size_t n) {
   return n % kChannelMessageAlignment == 0;
