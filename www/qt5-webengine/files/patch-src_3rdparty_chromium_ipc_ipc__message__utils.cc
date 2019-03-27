--- src/3rdparty/chromium/ipc/ipc_message_utils.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ipc/ipc_message_utils.cc
@@ -348,7 +348,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
   l->append(base::NumberToString(p));
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || defined(OS_FUCHSIA) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
