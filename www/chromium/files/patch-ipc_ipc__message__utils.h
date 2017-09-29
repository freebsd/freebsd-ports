--- ipc/ipc_message_utils.h.orig	2017-09-05 21:05:21.000000000 +0200
+++ ipc/ipc_message_utils.h	2017-09-06 20:44:35.248663000 +0200
@@ -212,7 +212,7 @@
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
-    (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
+    defined(OS_BSD) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
   typedef long param_type;
