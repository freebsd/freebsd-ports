--- VTK/Rendering/ANARI/vtkAnariLightNode.cxx.orig	2026-09-29 17:25:09 UTC
+++ VTK/Rendering/ANARI/vtkAnariLightNode.cxx
@@ -20,12 +20,46 @@
 #include <anari/anari_cpp.hpp>
 #include <anari/anari_cpp/ext/std.h>
 
+#include <type_traits>
 #include <vector>
 
 using vec3 = anari::std_types::vec3;
 
 VTK_ABI_NAMESPACE_BEGIN
 
+namespace
+{
+
+// The ANARI 1.0 specification's KHR_AREA_LIGHTS extension for light visibility
+// was removed in ANARI 1.1.
+// Patched in the master branch of VTK (c02fc7d) but not yet present in the releases.
+template <typename ExtensionsT, typename = void>
+struct AnariHasPrimaryVisibility : std::false_type
+{
+};
+
+template <typename ExtensionsT>
+struct AnariHasPrimaryVisibility<ExtensionsT,
+  decltype(void(std::declval<const ExtensionsT&>().ANARI_KHR_LIGHT_PRIMARY_VISIBILITY))>
+  : std::true_type
+{
+};
+
+template <typename ExtensionsT>
+bool AnariSupportsLightVisibility(const ExtensionsT& extensions)
+{
+  if constexpr (AnariHasPrimaryVisibility<ExtensionsT>::value)
+  {
+    return extensions.ANARI_KHR_LIGHT_PRIMARY_VISIBILITY != 0;
+  }
+  else
+  {
+    return extensions.ANARI_KHR_AREA_LIGHTS != 0;
+  }
+}
+
+} // anonymous namespace
+
 struct vtkAnariLightNodeInternals
 {
   vtkAnariSceneGraph* RendererNode{ nullptr };
@@ -328,18 +362,9 @@ void vtkAnariLightNode::Synchronize(bool prepass)
         anari::setParameter(anariDevice, anariLight, "position", lightPosition);
         // The overall amount of light emitted by the light in a direction in W/sr
         anari::setParameter(anariDevice, anariLight, "intensity", lightIntensity);
-
         // The size of the point light
-        if (anariExtensions.ANARI_KHR_AREA_LIGHTS)
-        {
-          float radius = static_cast<float>(vtkAnariLightNode::GetRadius(light));
-          anari::setParameter(anariDevice, anariLight, "radius", radius);
-        }
-        else
-        {
-          this->Internals->RendererNode->WarningMacroOnce(
-            this, " doesn't support KHR_AREA_LIGHTS::radius");
-        }
+        float radius = static_cast<float>(vtkAnariLightNode::GetRadius(light));
+        anari::setParameter(anariDevice, anariLight, "radius", radius);
       }
       else
       {
@@ -390,17 +415,9 @@ void vtkAnariLightNode::Synchronize(bool prepass)
         static_cast<float>(vtkAnariLightNode::GetLightScale(light) * light->GetIntensity());
       anari::setParameter(anariDevice, anariLight, "irradiance", irradiance);
 
-      if (anariExtensions.ANARI_KHR_AREA_LIGHTS)
-      {
-        float radius = static_cast<float>(vtkAnariLightNode::GetRadius(light));
-        // apparent size (angle in radians) of the light
-        anari::setParameter(anariDevice, anariLight, "angularDiameter", radius);
-      }
-      else
-      {
-        this->Internals->RendererNode->WarningMacroOnce(
-          this, " doesn't support KHR_AREA_LIGHTS::angularDiameter");
-      }
+      float radius = static_cast<float>(vtkAnariLightNode::GetRadius(light));
+      // apparent size (angle in radians) of the light
+      anari::setParameter(anariDevice, anariLight, "angularDiameter", radius);
     }
     else
     {
@@ -414,7 +431,7 @@ void vtkAnariLightNode::Synchronize(bool prepass)
     // All light sources accept the following parameters
     anari::setParameter(anariDevice, anariLight, "color", lightColor);
 
-    if (anariExtensions.ANARI_KHR_AREA_LIGHTS)
+    if (::AnariSupportsLightVisibility(anariExtensions))
     {
       bool isVisible = light->GetSwitch() ? true : false;
       anari::setParameter(anariDevice, anariLight, "visible", isVisible);
@@ -422,7 +439,7 @@ void vtkAnariLightNode::Synchronize(bool prepass)
     else
     {
       this->Internals->RendererNode->WarningMacroOnce(
-        this, " doesn't support KHR_AREA_LIGHTS::visible");
+        this, " doesn't support light visibility (KHR_LIGHT_PRIMARY_VISIBILITY::visible).");
     }
 
     anari::commitParameters(anariDevice, anariLight);
