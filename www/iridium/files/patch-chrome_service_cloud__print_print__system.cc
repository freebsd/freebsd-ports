--- chrome/service/cloud_print/print_system.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/service/cloud_print/print_system.cc
@@ -36,7 +36,7 @@ std::string PrintSystem::GenerateProxyId() {
   return base::GenerateGUID();
 }
 
-#if defined(OS_LINUX) && !defined(USE_CUPS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(USE_CUPS)
 scoped_refptr<PrintSystem> PrintSystem::CreateInstance(
     const base::DictionaryValue*) {
   return nullptr;
