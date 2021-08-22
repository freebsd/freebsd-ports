--- ipc/ipc_message_utils.cc.orig	2021-07-19 18:45:18 UTC
+++ ipc/ipc_message_utils.cc
@@ -353,7 +353,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
   l->append(base::NumberToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_FUCHSIA) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
