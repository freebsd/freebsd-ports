--- CMake/hoomd/HOOMDMPISetup.cmake.orig	2022-01-21 08:21:04 UTC
+++ CMake/hoomd/HOOMDMPISetup.cmake
@@ -13,7 +13,7 @@ if (ENABLE_MPI)
 
         find_path(cereal_INCLUDE_DIR NAMES cereal/cereal.hpp
             PATHS ${CMAKE_INSTALL_PREFIX}/include)
-        add_library(cereal INTERFACE IMPORTED)
+        #add_library(cereal INTERFACE IMPORTED)
         set_target_properties(cereal PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${cereal_INCLUDE_DIR}")
         find_package_message(cereal "Could not find cereal, assuming it is on a default path" "[${cereal_INCLUDE_DIR}]")
     endif()
