--- cmake/Functions.cmake.orig	2025-08-18 00:53:11 UTC
+++ cmake/Functions.cmake
@@ -103,7 +103,7 @@ function(add_linker_options target buildDir completeSt
     set(libs_rsp "${buildDir}/${ninjaTarget}_libs.rsp")
     set(ldir_rsp "${buildDir}/${ninjaTarget}_ldir.rsp")
     set_target_properties(${cmakeTarget} PROPERTIES STATIC_LIBRARY_OPTIONS "@${objects_rsp}")
-    if(LINUX OR ANDROID)
+    if(LINUX OR ANDROID OR FREEBSD)
          get_gn_arch(cpu ${TEST_architecture_arch})
          if(CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm" AND ${config} STREQUAL "Debug")
              target_link_options(${cmakeTarget} PRIVATE "LINKER:--long-plt")
@@ -373,6 +373,20 @@ function(add_gn_build_artifacts_to_target)
             set_target_properties(${arg_CMAKE_TARGET} PROPERTIES
                 LINK_DEPENDS ${arg_BUILDDIR}/${config}/${arch}/${arg_NINJA_STAMP}
             )
+            # For some reason when the build of QtWebEngine's "convert_dict" is
+            # completed the "convert_dict.stamp" isn't created.
+            #
+            # Work around this issue by creating "convert_dict.stamp" manually.
+            if(${arg_NINJA_TARGET} STREQUAL "convert_dict")
+                add_custom_command(
+                    POST_BUILD
+                    COMMENT "Add workaround for missing ${arg_NINJA_TARGET}.stamp file after build"
+                    COMMAND ${CMAKE_COMMAND} -E touch ${buildDir}/${config}/${arch}/${arg_NINJA_TARGET}.stamp
+                    TARGET ${target}
+                    DEPENDS run_${module}_NinjaDone
+                    USES_TERMINAL
+            )
+            endif()
             if(QT_IS_MACOS_UNIVERSAL)
                 add_intermediate_archive(${target} ${arg_BUILDDIR}/${config}/${arch} ${arg_COMPLETE_STATIC})
             elseif(IOS)
