--- aten/src/ATen/native/vulkan/ops/Clamp.cpp.orig	2026-04-17 23:38:43 UTC
+++ aten/src/ATen/native/vulkan/ops/Clamp.cpp
@@ -601,7 +601,7 @@ TORCH_LIBRARY_IMPL(aten, Vulkan, m) {
   m.impl(TORCH_SELECTIVE_NAME("aten::hardsigmoid"), hardsigmoid);
   m.impl(TORCH_SELECTIVE_NAME("aten::hardsigmoid_"), hardsigmoid_);
   m.impl(TORCH_SELECTIVE_NAME("aten::hardshrink"), hardshrink);
-  m.impl(TORCH_SELECTIVE_NAME("aten::hardshrink_"), hardshrink_);
+  // aten::hardshrink_ has no schema in native_functions.yaml
   m.impl(TORCH_SELECTIVE_NAME("aten::hardswish"), hardswish);
   m.impl(TORCH_SELECTIVE_NAME("aten::hardswish_"), hardswish_);
   m.impl(TORCH_SELECTIVE_NAME("aten::hardtanh"), hardtanh);
