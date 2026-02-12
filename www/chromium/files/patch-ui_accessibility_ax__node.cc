--- ui/accessibility/ax_node.cc.orig	2026-02-11 09:05:39 UTC
+++ ui/accessibility/ax_node.cc
@@ -1546,7 +1546,7 @@ AXNode::GetExtraMacNodes() const {
   return &table_info->extra_mac_nodes;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 AXNode* AXNode::GetExtraAnnouncementNode(
     ax::mojom::AriaNotificationPriority priority_property) const {
   if (!tree_->extra_announcement_nodes()) {
@@ -1574,7 +1574,7 @@ bool AXNode::IsGenerated() const {
       GetRole() == ax::mojom::Role::kColumn ||
       GetRole() == ax::mojom::Role::kTableHeaderContainer;
   DCHECK_EQ(is_generated_node, is_extra_mac_node_role);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // On Linux and Windows, generated nodes are always children of the root, but
   // not necessarily the root tree.
   if (GetParent() && GetParent()->GetManager()) {
