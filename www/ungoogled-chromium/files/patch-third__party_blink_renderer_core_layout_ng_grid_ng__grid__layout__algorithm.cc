--- third_party/blink/renderer/core/layout/ng/grid/ng_grid_layout_algorithm.cc.orig	2023-09-17 07:59:53 UTC
+++ third_party/blink/renderer/core/layout/ng/grid/ng_grid_layout_algorithm.cc
@@ -3431,7 +3431,13 @@ void NGGridLayoutAlgorithm::PlaceGridItems(
   DCHECK(out_row_break_between);
 
   const auto& container_space = ConstraintSpace();
+#if defined(__clang__) && (__clang_major__ >= 16)
   const auto& [grid_items, layout_data, tree_size] = sizing_tree.TreeRootData();
+#else
+  const auto& [g_i, l_d, t_s] = sizing_tree.TreeRootData();
+  const auto& grid_items = g_i;
+  const auto& layout_data = l_d;
+#endif
 
   const auto* cached_layout_subtree = container_space.GridLayoutSubtree();
   const auto container_writing_direction =
@@ -3595,7 +3601,13 @@ void NGGridLayoutAlgorithm::PlaceGridItemsForFragmenta
 
   // TODO(ikilpatrick): Update |SetHasSeenAllChildren| and early exit if true.
   const auto& constraint_space = ConstraintSpace();
+#if defined(__clang__) && (__clang_major__ >= 16)
   const auto& [grid_items, layout_data, tree_size] = sizing_tree.TreeRootData();
+#else
+  const auto& [g_i, l_d, t_s] = sizing_tree.TreeRootData();
+  const auto& grid_items = g_i;
+  const auto& layout_data = l_d;
+#endif
 
   const auto* cached_layout_subtree = constraint_space.GridLayoutSubtree();
   const auto container_writing_direction =
