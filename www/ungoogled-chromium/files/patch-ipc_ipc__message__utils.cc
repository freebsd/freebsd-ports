--- ipc/ipc_message_utils.cc.orig	2024-02-25 20:22:18 UTC
+++ ipc/ipc_message_utils.cc
@@ -394,7 +394,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) ||                                              \
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD) ||                         \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
