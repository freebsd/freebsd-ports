--- cmake/Modules/ECMGeneratePriFile.cmake.orig	2022-08-27 09:22:23 UTC
+++ cmake/Modules/ECMGeneratePriFile.cmake
@@ -92,7 +92,7 @@ else()
   query_qmake(qt_host_data_dir QT_HOST_DATA)
   set(ECM_MKSPECS_INSTALL_DIR ${qt_host_data_dir}/mkspecs/modules CACHE PATH "The directory where mkspecs will be installed to.")
 else()
-  set(ECM_MKSPECS_INSTALL_DIR mkspecs/modules CACHE PATH "The directory where mkspecs will be installed to.")
+    set(ECM_MKSPECS_INSTALL_DIR ${QT_MKSPECDIR_REL}/modules CACHE PATH "The directory where mkspecs will be installed to.")
 endif()
 
 function(ECM_GENERATE_PRI_FILE)
