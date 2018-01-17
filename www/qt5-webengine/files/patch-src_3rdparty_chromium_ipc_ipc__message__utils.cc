--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2017-01-26 00:49:15 UTC
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -425,7 +425,7 @@ void ParamTraits<unsigned int>::Log(cons
   l->append(base::UintToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::Int64ToString(static_cast<int64_t>(p)));
