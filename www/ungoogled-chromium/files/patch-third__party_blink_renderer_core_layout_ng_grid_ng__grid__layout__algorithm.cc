--- third_party/blink/renderer/core/layout/ng/grid/ng_grid_layout_algorithm.cc.orig	2023-05-05 12:12:41 UTC
+++ third_party/blink/renderer/core/layout/ng/grid/ng_grid_layout_algorithm.cc
@@ -516,8 +516,15 @@ wtf_size_t NGGridLayoutAlgorithm::BuildGridSizingSubtr
                                 row_auto_repetitions);
 
   bool has_nested_subgrid = false;
+#if defined(__clang__) && (__clang_major__ >= 16)
   auto& [grid_items, layout_data, subtree_size] =
       sizing_tree->CreateSizingData();
+#else
+  auto& sizing_data = sizing_tree->CreateSizingData();
+  auto& layout_data = sizing_data.layout_data;
+  auto& grid_items = sizing_data.grid_items;
+  auto& subtree_size = sizing_data.subtree_size;
+#endif
 
   if (!must_ignore_children) {
     // Construct grid items that are not subgridded.
@@ -1540,8 +1547,15 @@ void NGGridLayoutAlgorithm::InitializeTrackSizes(
     NGGridSizingTree* sizing_tree) const {
   DCHECK(sizing_tree && current_grid_index < sizing_tree->Size());
 
+#if defined(__clang__) && (__clang_major__ >= 16)
   auto& [grid_items, layout_data, subtree_size] =
       sizing_tree->At(current_grid_index);
+#else
+  auto& sizing_data = sizing_tree->At(current_grid_index);
+  auto& layout_data = sizing_data.layout_data;
+  auto& grid_items = sizing_data.grid_items;
+  auto& subtree_size = sizing_data.subtree_size;
+#endif
 
   auto InitAndCacheTrackSizes = [&](GridTrackSizingDirection track_direction) {
     InitializeTrackCollection(opt_subgrid_data, track_direction, &layout_data);
