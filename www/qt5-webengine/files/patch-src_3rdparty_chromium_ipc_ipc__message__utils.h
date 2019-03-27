--- src/3rdparty/chromium/ipc/ipc_message_utils.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ipc/ipc_message_utils.h
@@ -203,7 +203,7 @@ struct ParamTraits<unsigned int> {
 //   3) Android 64 bit and Fuchsia also have int64_t typedef'd to long.
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || defined(OS_FUCHSIA) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
