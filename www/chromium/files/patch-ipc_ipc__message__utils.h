--- ipc/ipc_message_utils.h.orig	2025-03-05 08:14:56 UTC
+++ ipc/ipc_message_utils.h
@@ -215,7 +215,7 @@ struct ParamTraits<unsigned int> {
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) ||                                              \
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) ||                         \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
