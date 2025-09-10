--- services/screen_ai/screen_ai_service_impl.cc.orig	2025-09-10 13:22:16 UTC
+++ services/screen_ai/screen_ai_service_impl.cc
@@ -38,7 +38,7 @@
 #include "ui/accessibility/ax_tree_id.h"
 #include "ui/gfx/geometry/rect_f.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "partition_alloc/buildflags.h"
 
 #if PA_BUILDFLAG( \
@@ -266,7 +266,7 @@ ScreenAIService::ScreenAIService(
     : factory_receiver_(this, std::move(receiver)),
       ocr_receiver_(this),
       main_content_extraction_receiver_(this) {
-#if BUILDFLAG(IS_LINUX) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && \
     PA_BUILDFLAG(          \
         ENABLE_ALLOCATOR_SHIM_PARTITION_ALLOC_DISPATCH_WITH_ADVANCED_CHECKS_SUPPORT)
   // TODO(crbug.com/418199684): Remove when the bug is fixed.
