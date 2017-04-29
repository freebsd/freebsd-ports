--- ipc/ipc_message_utils.cc.orig	2017-04-19 19:06:35 UTC
+++ ipc/ipc_message_utils.cc
@@ -421,7 +421,7 @@ void ParamTraits<unsigned int>::Log(cons
   l->append(base::UintToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::Int64ToString(static_cast<int64_t>(p)));
