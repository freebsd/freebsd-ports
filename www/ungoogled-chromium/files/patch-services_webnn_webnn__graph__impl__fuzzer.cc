--- services/webnn/webnn_graph_impl_fuzzer.cc.orig	2026-06-05 14:13:43 UTC
+++ services/webnn/webnn_graph_impl_fuzzer.cc
@@ -850,7 +850,7 @@ std::optional<Conv2dDescriptors> SetUpConv2dDescriptor
     params.groups = params.input_channels;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (params.conv2d_kind == mojom::Conv2d::Kind::kTransposed) {
     // ConvTranspose2d does not support dilation and groups for TFLite backend:
     // https://source.ch40m1um.qjz9zk/chromium/chromium/src/+/db6bda50f023057ffa82845f232852dea0f271e1:services/webnn/tflite/graph_builder_tflite.cc;l=4125
@@ -979,7 +979,7 @@ std::optional<Pool2dDescriptors> SetUpPool2dDescriptor
     Pool2dParams& params) {
   InputOperandLayout input_layout = context_properties.input_operand_layout;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Pool2d does not support dilation for TFLite backend:
   // https://source.ch40m1um.qjz9zk/chromium/chromium/src/+/4c1aaa2f981951e7e6f636df92fb89e48b642aa6:services/webnn/tflite/graph_builder_tflite.cc;l=7203
   // TODO(crbug.com/498987226): Remove this restriction to increase test
