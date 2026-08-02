--- cmake/OpenSimMacros.cmake.orig	2026-06-18 22:26:24 UTC
+++ cmake/OpenSimMacros.cmake
@@ -619,8 +619,8 @@ function(OpenSimInstallVisualizer DEP_LIBS_DIR_WIN
             set(simbody_visualizer "${DEP_LIBS_DIR_UNIX}/../libexec/simbody/simbody-visualizer")
             install(FILES ${simbody_visualizer} DESTINATION "${OSIM_DESTINATION}")
             # On Linux, the visualizer is a dynamically linked executable, we need fix rpath
-            execute_process(COMMAND bash "-c" "patchelf --set-rpath '$ORIGIN/:$ORIGIN/../../lib' '${simbody_visualizer}'" OUTPUT_VARIABLE res)
-            message(STATUS "patchelf --set-rpath '$ORIGIN/:.$ORIGIN/../../lib' '${simbody_visualizer}' '${res}'")
+            #execute_process(COMMAND bash "-c" "patchelf --set-rpath '$ORIGIN/:$ORIGIN/../../lib' '${simbody_visualizer}'" OUTPUT_VARIABLE res)
+            #message(STATUS "patchelf --set-rpath '$ORIGIN/:.$ORIGIN/../../lib' '${simbody_visualizer}' '${res}'")
         endif()
     endif()
 endfunction()
