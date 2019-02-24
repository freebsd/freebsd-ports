--- content/renderer/renderer_blink_platform_impl.h.orig	2019-01-30 02:18:00.000000000 +0100
+++ content/renderer/renderer_blink_platform_impl.h	2019-02-06 23:14:36.979983000 +0100
@@ -29,7 +29,7 @@
 #include "third_party/blink/public/platform/modules/cache_storage/cache_storage.mojom.h"
 #include "third_party/blink/public/platform/modules/webdatabase/web_database.mojom.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -264,7 +264,7 @@
   std::unique_ptr<service_manager::Connector> connector_;
   scoped_refptr<base::SingleThreadTaskRunner> io_runner_;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
@@ -299,7 +299,7 @@
   blink::mojom::CodeCacheHostPtrInfo code_cache_host_info_;
   scoped_refptr<blink::mojom::ThreadSafeCodeCacheHostPtr> code_cache_host_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   class SandboxSupport;
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
