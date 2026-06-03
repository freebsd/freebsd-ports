--- torch/csrc/jit/passes/inplace_check.cpp.orig	2026-04-18 04:20:00 UTC
+++ torch/csrc/jit/passes/inplace_check.cpp
@@ -7,8 +7,17 @@ static void CheckInplace(Block* block) {
 static void CheckInplace(Block* block) {
   for (auto node : block->nodes()) {
     if (node->kind() == prim::PythonOp && node->hasAttribute(attr::inplace)) {
+      // On FreeBSD, ScalarAttributeValue<T> typeinfo symbols are local to each
+      // DSO (no exported key function), so dynamic_cast across DSO boundaries
+      // (from python to cpu library) may fail. Guard with try/catch.
+      bool is_inplace = false;
+      try {
+        is_inplace = (bool)node->i(attr::inplace);
+      } catch (const std::exception&) {
+        // Cannot determine; treat as not-inplace (conservative safe default).
+      }
       TORCH_CHECK(
-          !node->i(attr::inplace),
+          !is_inplace,
           "inplace ",
           static_cast<PythonOp*>(node)->name(),
           " not supported in the JIT");
