--- cmake/modules/DunePythonVirtualenv.cmake.orig	2026-01-09 13:06:10 UTC
+++ cmake/modules/DunePythonVirtualenv.cmake
@@ -254,14 +254,17 @@ endif()
 # Also write a small wrapper script 'run-in-dune-env' into the build directory
 # This is necessary to execute installed python scripts (the bin path of a virtualenv
 # is *not* in the sys path, so a simple `python scriptname` does not work.
-if(UNIX)
+# Only needed when python bindings are enabled and the template exists
+if(UNIX AND DUNE_ENABLE_PYTHONBINDINGS)
   find_package(UnixCommands QUIET)
   dune_module_path(MODULE dune-common
                    RESULT scriptdir
                    SCRIPT_DIR)
-  configure_file(${scriptdir}/run-in-dune-env.sh.in
-                 ${CMAKE_BINARY_DIR}/run-in-dune-env
-                 @ONLY)
+  if(EXISTS "${scriptdir}/run-in-dune-env.sh.in")
+    configure_file(${scriptdir}/run-in-dune-env.sh.in
+                   ${CMAKE_BINARY_DIR}/run-in-dune-env
+                   @ONLY)
+  endif()
 else()
   message(WARNING "Writing script 'run-in-dune-env' not implemented on your platform!")
 endif()
