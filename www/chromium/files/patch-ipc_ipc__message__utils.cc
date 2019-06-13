--- ipc/ipc_message_utils.cc.orig	2019-06-04 18:55:25 UTC
+++ ipc/ipc_message_utils.cc
@@ -356,7 +356,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
   l->append(base::NumberToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
