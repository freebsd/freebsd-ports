--- content/browser/webui/shared_resources_data_source.cc.orig	2019-04-30 22:22:47 UTC
+++ content/browser/webui/shared_resources_data_source.cc
@@ -102,9 +102,9 @@ const std::map<int, std::string> CreateMojoResourceIdT
         {IDR_MOJO_BIG_BUFFER_MOJOM_LITE_JS, "js/big_buffer.mojom-lite.js"},
         {IDR_MOJO_FILE_MOJOM_LITE_JS, "js/file.mojom-lite.js"},
         {IDR_MOJO_STRING16_MOJOM_LITE_JS, "js/string16.mojom-lite.js"},
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         {IDR_MOJO_TIME_MOJOM_LITE_JS, "js/time.mojom-lite.js"},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   };
 }
 
