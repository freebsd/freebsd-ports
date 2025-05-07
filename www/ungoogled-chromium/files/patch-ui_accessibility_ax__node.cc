--- ui/accessibility/ax_node.cc.orig	2025-05-06 12:23:00 UTC
+++ ui/accessibility/ax_node.cc
@@ -1553,7 +1553,7 @@ AXNode::GetExtraMacNodes() const {
   return &table_info->extra_mac_nodes;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 AXNode* AXNode::GetExtraAnnouncementNode(
     ax::mojom::AriaNotificationPriority priority_property) const {
   if (!tree_->extra_announcement_nodes()) {
@@ -1581,7 +1581,7 @@ bool AXNode::IsGenerated() const {
       GetRole() == ax::mojom::Role::kColumn ||
       GetRole() == ax::mojom::Role::kTableHeaderContainer;
   DCHECK_EQ(is_generated_node, is_extra_mac_node_role);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   //  On Linux, generated nodes are always children of the root.
   if (GetParent() && GetParent()->GetManager()) {
     DCHECK(GetParent()->GetManager()->IsRoot());
