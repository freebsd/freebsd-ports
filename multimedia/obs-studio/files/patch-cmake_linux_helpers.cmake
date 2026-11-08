-- Do not copy the Chromium Embedded Framework shared libraries and resources
-- into the obs-studio package on FreeBSD.  They are provided by the www/cef
-- dependency, and copying libcef.so into the staging area causes stage-qa
-- failures because the port does not declare all of CEF's own library
-- dependencies.
--
-- RPATH set in plugins/obs-browser/cmake/os-linux.cmake already points to
-- the system CEF directory so the obs-browser plugin can load libcef.so.
--- cmake/linux/helpers.cmake.orig	2026-10-29 21:06:35 UTC
+++ cmake/linux/helpers.cmake
@@ -171,50 +171,53 @@ function(set_target_properties_obs target)
         if(imported_location)
           cmake_path(GET imported_location PARENT_PATH cef_location)
           cmake_path(GET cef_location PARENT_PATH cef_root_location)
-          add_custom_command(
-            TARGET ${target}
-            POST_BUILD
-            COMMAND "${CMAKE_COMMAND}" -E make_directory "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core"
-            COMMAND
-              "${CMAKE_COMMAND}" -E copy_if_different "${imported_location}" "${cef_location}/chrome-sandbox"
-              "${cef_location}/libEGL.so" "${cef_location}/libGLESv2.so" "${cef_location}/libvk_swiftshader.so"
-              "${cef_location}/libvulkan.so.1" "${cef_location}/v8_context_snapshot.bin"
-              "${cef_location}/vk_swiftshader_icd.json" "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core"
-            COMMAND
-              "${CMAKE_COMMAND}" -E copy_if_different "${cef_root_location}/Resources/chrome_100_percent.pak"
-              "${cef_root_location}/Resources/chrome_200_percent.pak" "${cef_root_location}/Resources/icudtl.dat"
-              "${cef_root_location}/Resources/resources.pak"
-              "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core"
-            COMMAND
-              "${CMAKE_COMMAND}" -E copy_directory "${cef_root_location}/Resources/locales"
-              "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core/locales"
-            COMMENT "Add Chromium Embedded Framework to library directory"
-          )
 
-          install(
-            FILES
-              "${imported_location}"
-              "${cef_location}/chrome-sandbox"
-              "${cef_location}/libEGL.so"
-              "${cef_location}/libGLESv2.so"
-              "${cef_location}/libvk_swiftshader.so"
-              "${cef_location}/libvulkan.so.1"
-              "${cef_location}/v8_context_snapshot.bin"
-              "${cef_location}/vk_swiftshader_icd.json"
-              "${cef_root_location}/Resources/chrome_100_percent.pak"
-              "${cef_root_location}/Resources/chrome_200_percent.pak"
-              "${cef_root_location}/Resources/icudtl.dat"
-              "${cef_root_location}/Resources/resources.pak"
-            DESTINATION "${OBS_PLUGIN_DESTINATION}/core"
-            COMPONENT Runtime
-          )
+          if(NOT OS_FREEBSD)
+            add_custom_command(
+              TARGET ${target}
+              POST_BUILD
+              COMMAND "${CMAKE_COMMAND}" -E make_directory "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core"
+              COMMAND
+                "${CMAKE_COMMAND}" -E copy_if_different "${imported_location}" "${cef_location}/chrome-sandbox"
+                "${cef_location}/libEGL.so" "${cef_location}/libGLESv2.so" "${cef_location}/libvk_swiftshader.so"
+                "${cef_location}/libvulkan.so.1" "${cef_location}/v8_context_snapshot.bin"
+                "${cef_location}/vk_swiftshader_icd.json" "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core"
+              COMMAND
+                "${CMAKE_COMMAND}" -E copy_if_different "${cef_root_location}/Resources/chrome_100_percent.pak"
+                "${cef_root_location}/Resources/chrome_200_percent.pak" "${cef_root_location}/Resources/icudtl.dat"
+                "${cef_root_location}/Resources/resources.pak"
+                "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core"
+              COMMAND
+                "${CMAKE_COMMAND}" -E copy_directory "${cef_root_location}/Resources/locales"
+                "${OBS_OUTPUT_DIR}/$<CONFIG>/${OBS_PLUGIN_DESTINATION}/core/locales"
+              COMMENT "Add Chromium Embedded Framework to library directory"
+            )
 
-          install(
-            DIRECTORY "${cef_root_location}/Resources/locales"
-            DESTINATION "${OBS_PLUGIN_DESTINATION}/core"
-            USE_SOURCE_PERMISSIONS
-            COMPONENT Runtime
-          )
+            install(
+              FILES
+                "${imported_location}"
+                "${cef_location}/chrome-sandbox"
+                "${cef_location}/libEGL.so"
+                "${cef_location}/libGLESv2.so"
+                "${cef_location}/libvk_swiftshader.so"
+                "${cef_location}/libvulkan.so.1"
+                "${cef_location}/v8_context_snapshot.bin"
+                "${cef_location}/vk_swiftshader_icd.json"
+                "${cef_root_location}/Resources/chrome_100_percent.pak"
+                "${cef_root_location}/Resources/chrome_200_percent.pak"
+                "${cef_root_location}/Resources/icudtl.dat"
+                "${cef_root_location}/Resources/resources.pak"
+              DESTINATION "${OBS_PLUGIN_DESTINATION}/core"
+              COMPONENT Runtime
+            )
+
+            install(
+              DIRECTORY "${cef_root_location}/Resources/locales"
+              DESTINATION "${OBS_PLUGIN_DESTINATION}/core"
+              USE_SOURCE_PERMISSIONS
+              COMPONENT Runtime
+            )
+          endif()
         endif()
       endif()
     endif()
