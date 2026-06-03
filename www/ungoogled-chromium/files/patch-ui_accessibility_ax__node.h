--- ui/accessibility/ax_node.h.orig	2026-05-09 18:09:27 UTC
+++ ui/accessibility/ax_node.h
@@ -580,7 +580,7 @@ class AX_EXPORT AXNode final {
   const std::vector<raw_ptr<AXNode, VectorExperimental>>* GetExtraMacNodes()
       const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   AXNode* GetExtraAnnouncementNode(
       ax::mojom::AriaNotificationPriority priority_property) const;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
