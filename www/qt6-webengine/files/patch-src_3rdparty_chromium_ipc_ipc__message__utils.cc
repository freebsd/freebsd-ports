--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -393,7 +393,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) ||                                              \
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) ||                         \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
