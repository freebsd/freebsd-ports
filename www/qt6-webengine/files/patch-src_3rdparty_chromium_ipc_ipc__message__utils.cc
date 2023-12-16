--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2022-05-19 14:06:27 UTC
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -359,7 +359,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) ||                                              \
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) ||                         \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
