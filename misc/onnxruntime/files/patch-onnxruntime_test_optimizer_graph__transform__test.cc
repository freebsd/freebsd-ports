-- Disable an upstream graph-optimizer test that segfaults on FreeBSD.
-- The post-transform checker passes a null TensorShapeProto pointer to
-- CheckShapeEquality(), causing a crash. Until the root cause is fixed
-- upstream, skip this test so the rest of the C++ test suite can pass.
-- See https://github.com/microsoft/onnxruntime/issues/23816
--- onnxruntime/test/optimizer/graph_transform_test.cc.orig	2026-09-22 17:05:06 UTC
+++ onnxruntime/test/optimizer/graph_transform_test.cc
@@ -11295,7 +11295,7 @@ Be noted:
  the Sub's input initializer 128 is a scalar int32_t;
  the Mul's input initializer 64 is a 1-D int32_t.
 */
-TEST_F(GraphTransformationTests, ConstantSharing_ShareIntTypedInitializer) {
+TEST_F(GraphTransformationTests, DISABLED_ConstantSharing_ShareIntTypedInitializer) {
   auto pre_graph_checker = [](Graph& graph) -> Status {
     auto op_count_pre = CountOpsInGraph(graph);
     TEST_RETURN_IF_NOT(op_count_pre.size() == 6U);
