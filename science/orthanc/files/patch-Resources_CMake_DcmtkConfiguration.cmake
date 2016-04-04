Fix the build with CMake 3.5.0.

FindDCMTK.cmake was rewritten upstream, and is incompatible with the uses in
this file: we need to set DCMTK_DIR in the port's Makefile, and it does not
match the directory used for searching for the headers below.
--- Resources/CMake/DcmtkConfiguration.cmake.orig	2015-12-15 16:49:02 UTC
+++ Resources/CMake/DcmtkConfiguration.cmake
@@ -186,10 +186,10 @@ else()
     -DHAVE_CONFIG_H=1
     )
 
-  if (EXISTS "${DCMTK_DIR}/config/cfunix.h")
-    set(DCMTK_CONFIGURATION_FILE "${DCMTK_DIR}/config/cfunix.h")
-  elseif (EXISTS "${DCMTK_DIR}/config/osconfig.h")  # This is for Arch Linux
-    set(DCMTK_CONFIGURATION_FILE "${DCMTK_DIR}/config/osconfig.h")
+  if (EXISTS "${DCMTK_config_INCLUDE_DIR}/cfunix.h")
+    set(DCMTK_CONFIGURATION_FILE "${DCMTK_config_INCLUDE_DIR}/cfunix.h")
+  elseif (EXISTS "${DCMTK_config_INCLUDE_DIR}/osconfig.h")  # This is for Arch Linux
+    set(DCMTK_CONFIGURATION_FILE "${DCMTK_config_INCLUDE_DIR}/osconfig.h")
   else()
     message(FATAL_ERROR "Please install libdcmtk*-dev")
   endif()
