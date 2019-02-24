--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2019-02-06 23:36:21.401100000 +0100
+++ third_party/blink/renderer/core/paint/paint_layer.cc	2019-02-06 23:38:08.649536000 +0100
@@ -104,7 +104,7 @@
 static CompositingQueryMode g_compositing_query_mode =
     kCompositingQueriesAreOnlyAllowedInCertainDocumentLifecyclePhases;
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
 struct SameSizeAsPaintLayer : DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
