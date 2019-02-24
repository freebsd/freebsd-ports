--- content/browser/webui/shared_resources_data_source.cc.orig	2019-02-06 23:05:16.881256000 +0100
+++ content/browser/webui/shared_resources_data_source.cc	2019-02-06 23:05:49.834217000 +0100
@@ -73,9 +73,9 @@
   return std::map<int, std::string> {
     {IDR_MOJO_MOJO_BINDINGS_JS, "js/mojo_bindings.js"},
         {IDR_MOJO_MOJO_BINDINGS_LITE_JS, "js/mojo_bindings_lite.js"},
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         {IDR_MOJO_TIME_MOJOM_JS, "js/time.mojom.js"},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   };
 }
 
