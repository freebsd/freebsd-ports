--- content/browser/generic_sensor/frame_sensor_provider_proxy.cc.orig	2024-02-04 14:46:08 UTC
+++ content/browser/generic_sensor/frame_sensor_provider_proxy.cc
@@ -20,7 +20,11 @@ namespace content {
 
 namespace {
 
+#if (_LIBCPP_VERSION >= 160000)
 constexpr std::vector<blink::mojom::PermissionsPolicyFeature>
+#else
+std::vector<blink::mojom::PermissionsPolicyFeature>
+#endif
 SensorTypeToPermissionsPolicyFeatures(SensorType type) {
   switch (type) {
     case SensorType::AMBIENT_LIGHT:
