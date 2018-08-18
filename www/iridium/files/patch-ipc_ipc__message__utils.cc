--- ipc/ipc_message_utils.cc.orig	2017-09-05 21:05:21.000000000 +0200
+++ ipc/ipc_message_utils.cc	2017-09-06 20:38:34.375119000 +0200
@@ -424,7 +424,7 @@
 }
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
-    (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
+    defined(OS_BSD) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::Int64ToString(static_cast<int64_t>(p)));
 }
