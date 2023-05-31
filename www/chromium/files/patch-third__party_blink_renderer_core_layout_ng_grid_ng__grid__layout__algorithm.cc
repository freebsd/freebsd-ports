--- third_party/blink/renderer/core/layout/ng/grid/ng_grid_layout_algorithm.cc.orig	2023-05-31 08:12:17 UTC
+++ third_party/blink/renderer/core/layout/ng/grid/ng_grid_layout_algorithm.cc
@@ -520,8 +520,15 @@ wtf_size_t NGGridLayoutAlgorithm::BuildGridSizingSubtr
                                 row_auto_repetitions);
 
   bool has_nested_subgrid = false;
+#if defined(__clang__) && (__clang_major__ >= 16)
   auto& [grid_items, layout_data, subtree_size] =
       sizing_tree->CreateSizingData(opt_subgrid_data);
+#else
+  auto& sizing_data = sizing_tree->CreateSizingData(opt_subgrid_data);
+  auto& layout_data = sizing_data.layout_data;
+  auto& grid_items = sizing_data.grid_items;
+  auto& subtree_size = sizing_data.subtree_size;
+#endif
 
   if (!must_ignore_children) {
     // Construct grid items that are not subgridded.
@@ -650,8 +657,14 @@ NGGridSizingTree NGGridLayoutAlgorithm::BuildGridSizin
   NGGridSizingTree sizing_tree;
 
   if (const auto* layout_subtree = ConstraintSpace().GridLayoutSubtree()) {
+#if defined(__clang__) && (__clang_major__ >= 16)
     auto& [grid_items, layout_data, subtree_size] =
         sizing_tree.CreateSizingData();
+#else
+    auto& sizing_data = sizing_tree.CreateSizingData();
+    auto& layout_data = sizing_data.layout_data;
+    auto& grid_items = sizing_data.grid_items;
+#endif
 
     const auto& node = Node();
     grid_items =
@@ -1640,8 +1653,15 @@ void NGGridLayoutAlgorithm::InitializeTrackSizes(
     const absl::optional<GridTrackSizingDirection>& opt_track_direction) const {
   DCHECK(sizing_subtree);
 
+#if defined(__clang__) && (__clang_major__ >= 16)
   auto& [grid_items, layout_data, subtree_size] =
       sizing_subtree.SubtreeRootData();
+#else
+  auto& sizing_data = sizing_subtree.SubtreeRootData();
+  auto& layout_data = sizing_data.layout_data;
+  auto& grid_items = sizing_data.grid_items;
+  auto& subtree_size = sizing_data.subtree_size;
+#endif
 
   auto InitAndCacheTrackSizes = [&](GridTrackSizingDirection track_direction) {
     InitializeTrackCollection(opt_subgrid_data, track_direction, &layout_data);
