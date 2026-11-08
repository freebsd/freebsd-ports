--- ui/accessibility/ax_tree.cc.orig	2026-08-31 10:59:09 UTC
+++ ui/accessibility/ax_tree.cc
@@ -698,7 +698,7 @@ struct AXTreeUpdateState {
   // (crrev.com/c/2892259).
   const raw_ref<const AXTreeUpdate> pending_tree_update;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool should_clear_extra_announcement_nodes = false;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -853,7 +853,7 @@ bool AXTree::ComputeNodeIsIgnoredChanged(
   return old_node_is_ignored != new_node_is_ignored;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 ExtraAnnouncementNodes::ExtraAnnouncementNodes(AXNode* root) {
   assertive_node_ = CreateNode("assertive", root);
   polite_node_ = CreateNode("polite", root);
@@ -930,7 +930,7 @@ AXNode* AXTree::GetFromId(AXNodeID id) const {
 
 void AXTree::Destroy() {
   base::ElapsedThreadTimer timer;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ClearExtraAnnouncementNodes();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -1585,7 +1585,7 @@ bool AXTree::Unserialize(const AXTreeUpdate& update) {
   observers_.Notify(&AXTreeObserver::OnAtomicUpdateFinished, this,
                     root_->id() != old_root_id, changes);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (update_state.should_clear_extra_announcement_nodes) {
     ClearExtraAnnouncementNodes();
   }
@@ -2188,7 +2188,7 @@ void AXTree::NotifyNodeAttributesWillChange(
                     new_data);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void AXTree::ClearExtraAnnouncementNodes() {
   if (!extra_announcement_nodes_) {
     return;
@@ -2589,7 +2589,7 @@ bool AXTree::CreateNewChildVector(
     AXTreeUpdateState* update_state) {
   DCHECK(GetTreeUpdateInProgressState());
   bool success = true;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // If the root node has children added, clear the extra announcement nodes,
   // which should always have their indices as the last two children of the root
   // node. They will be recreated if needed, and given the correct indices.
