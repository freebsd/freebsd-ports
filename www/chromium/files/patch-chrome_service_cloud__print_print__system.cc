--- chrome/service/cloud_print/print_system.cc.orig	2018-03-24 13:33:28.414570000 +0100
+++ chrome/service/cloud_print/print_system.cc	2018-03-24 13:31:35.144592000 +0100
@@ -36,7 +36,7 @@
   return base::GenerateGUID();
 }
 
-#if defined(OS_LINUX) && !defined(USE_CUPS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(USE_CUPS)
 scoped_refptr<PrintSystem> PrintSystem::CreateInstance(
     const base::DictionaryValue*) {
   return nullptr;
