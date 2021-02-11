--- cmake/external.cmake.orig	2021-02-03 11:42:41 UTC
+++ cmake/external.cmake
@@ -141,3 +141,13 @@ function(link_x11 target_name)
         target_link_libraries(${target_name} PRIVATE ${X11_Xtst_LIB})
     endif()
 endfunction()
+
+# usrsctp
+function(link_usrsctp target_name)
+    if (TG_OWT_PACKAGED_BUILD)
+        find_package(PkgConfig REQUIRED)
+        pkg_check_modules(USRSCTP REQUIRED usrsctp)
+        target_include_directories(${target_name} PRIVATE ${USRSCTP_INCLUDE_DIRS})
+        target_link_libraries(${target_name} PRIVATE ${USRSCTP_LINK_LIBRARIES})
+    endif()
+endfunction()
