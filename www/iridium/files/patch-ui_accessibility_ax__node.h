--- ui/accessibility/ax_node.h.orig	2025-09-11 13:19:19 UTC
+++ ui/accessibility/ax_node.h
@@ -582,7 +582,7 @@ class AX_EXPORT AXNode final {
   const std::vector<raw_ptr<AXNode, VectorExperimental>>* GetExtraMacNodes()
       const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AXNode* GetExtraAnnouncementNode(
       ax::mojom::AriaNotificationPriority priority_property) const;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
