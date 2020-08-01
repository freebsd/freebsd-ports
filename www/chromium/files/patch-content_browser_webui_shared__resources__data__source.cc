--- content/browser/webui/shared_resources_data_source.cc.orig	2020-07-07 21:58:15 UTC
+++ content/browser/webui/shared_resources_data_source.cc
@@ -130,13 +130,13 @@ const std::map<int, std::string> CreateMojoResourceIdT
          "mojo/mojo/public/mojom/base/text_direction.mojom.html"},
         {IDR_MOJO_TEXT_DIRECTION_MOJOM_LITE_JS,
          "mojo/mojo/public/mojom/base/text_direction.mojom-lite.js"},
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_ANDROID)
         {IDR_MOJO_TIME_MOJOM_HTML,
          "mojo/mojo/public/mojom/base/time.mojom.html"},
         {IDR_MOJO_TIME_MOJOM_LITE_JS,
          "mojo/mojo/public/mojom/base/time.mojom-lite.js"},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         //  defined(OS_ANDROID)
   };
 }
