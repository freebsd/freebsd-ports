--- ipc/ipc_message_utils.cc.orig	2016-05-20 21:47:31 UTC
+++ ipc/ipc_message_utils.cc
@@ -414,7 +414,7 @@ void ParamTraits<unsigned int>::Log(cons
   l->append(base::UintToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::Int64ToString(static_cast<int64_t>(p)));
