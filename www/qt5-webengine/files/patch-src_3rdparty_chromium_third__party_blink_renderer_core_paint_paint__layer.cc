--- src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/core/paint/paint_layer.cc
@@ -110,7 +110,7 @@ static CompositingQueryMode g_compositing_query_mode =
 static CompositingQueryMode g_compositing_query_mode =
     kCompositingQueriesAreOnlyAllowedInCertainDocumentLifecyclePhases;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 struct SameSizeAsPaintLayer : DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
