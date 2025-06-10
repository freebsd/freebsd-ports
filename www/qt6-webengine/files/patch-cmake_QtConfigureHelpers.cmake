--- cmake/QtConfigureHelpers.cmake.orig	2025-02-21 12:29:33 UTC
+++ cmake/QtConfigureHelpers.cmake
@@ -191,7 +191,7 @@ function(qt_webengine_configure_check_for_ulimit)
 
 function(qt_webengine_configure_check_for_ulimit)
     message(STATUS "Checking 'ulimit -n'")
-    execute_process(COMMAND bash -c "ulimit -n"
+    execute_process(COMMAND sh -c "ulimit -n"
         OUTPUT_VARIABLE ulimit_output
     )
     string(REGEX MATCHALL "[0-9]+" limit "${ulimit_output}")
@@ -200,7 +200,7 @@ function(qt_webengine_configure_check_for_ulimit)
         if(NOT ${CMAKE_VERSION} VERSION_LESS "3.21.0")
             message(STATUS "Creating linker launcher")
             file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/linker_ulimit.sh
-                CONTENT "#!/bin/bash\nulimit -n 4096\nexec \"$@\""
+                CONTENT "#!/bin/sh\nulimit -n 4096\nexec \"$@\""
                 FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
             )
             set(COIN_BUG_699 ON PARENT_SCOPE)
