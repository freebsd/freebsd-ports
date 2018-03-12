--- chrome/service/cloud_print/print_system.cc.orig	2018-02-24 15:25:11 UTC
+++ chrome/service/cloud_print/print_system.cc
@@ -5,6 +5,7 @@
 #include "chrome/service/cloud_print/print_system.h"
 
 #include "base/guid.h"
+#include "build/build_config.h"
 
 namespace cloud_print {
 
@@ -35,5 +36,12 @@ std::string PrintSystem::GenerateProxyId
   return base::GenerateGUID();
 }
 
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(USE_CUPS)
+scoped_refptr<PrintSystem> PrintSystem::CreateInstance(
+    const base::DictionaryValue*) {
+  return nullptr;
+}
+#endif
+
 }  // namespace cloud_print
 
