--- examples/vulkan/Vulkan.cpp.orig	2026-08-25 01:40:29 UTC
+++ examples/vulkan/Vulkan.cpp
@@ -908,7 +908,7 @@ class VulkanExample (public)
         // Use the vertex shader SPIR-V code to create a vertex shader module
         {
             sf::FileInputStream file;
-            if (!file.open("resources/shader.vert.spv"))
+            if (!file.open("%%DATADIR%%/shader.vert.spv"))
             {
                 vulkanAvailable = false;
                 return;
@@ -936,7 +936,7 @@ class VulkanExample (public)
         // Use the fragment shader SPIR-V code to create a fragment shader module
         {
             sf::FileInputStream file;
-            if (!file.open("resources/shader.frag.spv"))
+            if (!file.open("%%DATADIR%%/shader.frag.spv"))
             {
                 vulkanAvailable = false;
                 return;
@@ -1787,7 +1787,7 @@ class VulkanExample (public)
     {
         // Load the image data
         sf::Image imageData;
-        if (!imageData.loadFromFile("resources/logo.png"))
+        if (!imageData.loadFromFile("%%DATADIR%%/logo.png"))
         {
             vulkanAvailable = false;
             return;
