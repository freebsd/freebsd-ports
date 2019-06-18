--- ipc/ipc_message_utils.h.orig	2019-03-11 22:00:59 UTC
+++ ipc/ipc_message_utils.h
@@ -204,7 +204,7 @@ struct ParamTraits<unsigned int> {
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
-    (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
+    defined(OS_BSD) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
   typedef long param_type;
