--- OrthancFramework/Resources/CMake/CivetwebConfiguration.cmake.orig	2021-08-30 20:14:33 UTC
+++ OrthancFramework/Resources/CMake/CivetwebConfiguration.cmake
@@ -109,32 +109,38 @@ else()
 
   cmake_reset_check_state()
   set(CMAKE_REQUIRED_LIBRARIES dl pthread)
-  CHECK_LIBRARY_EXISTS(civetweb mg_start "" HAVE_CIVETWEB_LIB)
-  if (NOT HAVE_CIVETWEB_LIB)
-    message(FATAL_ERROR "Please install the libcivetweb-dev package")
-  endif()
 
-  link_libraries(civetweb)
+  find_library(CIVETWEB_LIB NAMES civetweb PATHS
+    /usr/lib
+    /usr/local/lib
+  )
 
-  # Check whether the system distribution of civetweb contains the
-  # patch "../Patches/civetweb-1.13.patch" that allows to disable
-  # keep-alive on selected HTTP connections. This is useful to speed
-  # up multipart transfers, as encountered in DICOMweb.
-  CHECK_LIBRARY_EXISTS(civetweb mg_disable_keep_alive "" CIVETWEB_HAS_DISABLE_KEEP_ALIVE_1)  # From "../Patches/civetweb-1.13.patch"
-  CHECK_LIBRARY_EXISTS(civetweb mg_disable_connection_keep_alive "" CIVETWEB_HAS_DISABLE_KEEP_ALIVE_2)  # From civetweb >= 1.14
-  if (CIVETWEB_HAS_DISABLE_KEEP_ALIVE_1 OR
-      CIVETWEB_HAS_DISABLE_KEEP_ALIVE_2)
-    add_definitions(
-      -DCIVETWEB_HAS_DISABLE_KEEP_ALIVE=1
-      -DCIVETWEB_HAS_WEBDAV_WRITING=1
-      )
-    message("Performance: Your system-wide distribution of civetweb is configured for best performance")
+  if (CIVETWEB_LIB)
+    CHECK_LIBRARY_EXISTS(${CIVETWEB_LIB} mg_start "" HAVE_CIVETWEB_LIB)
+    if (NOT HAVE_CIVETWEB_LIB)
+      message(FATAL_ERROR "Unable to use mg_start from civetweb library")
+    endif()
+
+    CHECK_LIBRARY_EXISTS(${CIVETWEB_LIB} mg_disable_connection_keep_alive "" CIVETWEB_HAS_DISABLE_KEEP_ALIVE)
+    if (CIVETWEB_HAS_DISABLE_KEEP_ALIVE)
+      add_definitions(
+        -DCIVETWEB_HAS_DISABLE_KEEP_ALIVE=1
+        -DCIVETWEB_HAS_WEBDAV_WRITING=1
+        )
+      message("Performance: Your system-wide distribution of civetweb is configured for best performance")
+    else()
+      message(WARNING "Performance: Your system-wide distribution of civetweb does not feature the mg_disable_connection_keep_alive() function, and WebDAV will only be available for read-only access")
+      add_definitions(
+        -DCIVETWEB_HAS_DISABLE_KEEP_ALIVE=0
+        -DCIVETWEB_HAS_WEBDAV_WRITING=0
+        )
+    endif()
+
+    get_filename_component(CIVETWEB_LIB_PATH ${CIVETWEB_LIB} DIRECTORY)
+    link_directories(${CIVETWEB_LIB_PATH})
+    link_libraries(civetweb)
   else()
-    message(WARNING "Performance: Your system-wide distribution of civetweb does not feature the mg_disable_keep_alive() function, and WebDAV will only be available for read-only access")
-    add_definitions(
-      -DCIVETWEB_HAS_DISABLE_KEEP_ALIVE=0
-      -DCIVETWEB_HAS_WEBDAV_WRITING=0
-      )
+    message(FATAL_ERROR "Unable to find the civetweb library")
   endif()
 
   unset(CMAKE_REQUIRED_LIBRARIES)  # This reset must be after "CHECK_LIBRARY_EXISTS"
