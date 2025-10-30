--- cmake/InstallTPLs.cmake.orig	2025-07-23 20:11:18 UTC
+++ cmake/InstallTPLs.cmake
@@ -84,7 +84,9 @@ set(SPHERAL_FP_DIRS )
 set(SPHERAL_FP_DIRS )
 
 # Use find_package to get axom (which brings in fmt) and patch fmt
-find_package(axom REQUIRED NO_DEFAULT_PATH PATHS ${axom_DIR}/lib/cmake)
+message("YURI CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
+set(CMAKE_PREFIX_PATH "/usr/local/lib/cmake") # not sure why this is needed here
+find_package(axom REQUIRED)
 list(APPEND SPHERAL_BLT_DEPENDS axom )
 list(APPEND SPHERAL_FP_TPLS axom)
 list(APPEND SPHERAL_FP_DIRS ${axom_DIR}/lib/cmake)
@@ -102,7 +104,7 @@ message("---------------------------------------------
 
 message("-----------------------------------------------------------------------------")
 # Use find_package to get adiak
-find_package(adiak REQUIRED NO_DEFAULT_PATH PATHS ${adiak_DIR}/lib/cmake/adiak)
+find_package(adiak REQUIRED)
 if(adiak_FOUND)
   list(APPEND SPHERAL_BLT_DEPENDS adiak::adiak)
   list(APPEND SPHERAL_FP_TPLS adiak)
@@ -112,7 +114,7 @@ message("---------------------------------------------
 
 message("-----------------------------------------------------------------------------")
 # Use find_package to get polytope
-find_package(polytope NO_DEFAULT_PATH PATHS ${polytope_DIR}/lib/cmake)
+find_package(polytope REQUIRED)
 if(POLYTOPE_FOUND)
   list(APPEND SPHERAL_BLT_DEPENDS polytope)
   list(APPEND SPHERAL_FP_TPLS polytope)
@@ -141,7 +143,7 @@ if (ENABLE_TIMER)
     # Only save if it does not exists already
     set(CONFIG_CALIPER_DIR "${caliper_DIR}" CACHE PATH "Configuration Caliper directory")
   endif()
-  find_package(caliper REQUIRED NO_DEFAULT_PATH PATHS ${caliper_DIR}/share/cmake/caliper)
+  find_package(caliper REQUIRED PATHS ${caliper_DIR}/share/cmake/caliper)
   if(caliper_FOUND)
     list(APPEND SPHERAL_BLT_DEPENDS caliper)
     list(APPEND SPHERAL_FP_TPLS caliper)
@@ -151,14 +153,14 @@ message("---------------------------------------------
 endif()
 
 message("-----------------------------------------------------------------------------")
-find_package(RAJA REQUIRED NO_DEFAULT_PATH PATHS ${raja_DIR})
+find_package(RAJA REQUIRED)
 if (RAJA_FOUND) 
   message("Found RAJA External Package.")
   blt_convert_to_system_includes(TARGET RAJA)
 endif()
 
 message("-----------------------------------------------------------------------------")
-find_package(umpire REQUIRED NO_DEFAULT_PATH PATHS ${umpire_DIR})
+find_package(umpire REQUIRED)
 if (umpire_FOUND) 
   message("Found umpire External Package.")
   blt_convert_to_system_includes(TARGET umpire)
@@ -166,8 +168,8 @@ message("---------------------------------------------
 
 message("-----------------------------------------------------------------------------")
 # Chai
-if(chai_DIR AND USE_EXTERNAL_CHAI)
-  find_package(chai REQUIRED NO_DEFAULT_PATH PATHS ${chai_DIR})
+if(USE_EXTERNAL_CHAI)
+  find_package(chai REQUIRED)
   if (chai_FOUND) 
     message("Found chai External Package.")
   endif()
@@ -190,12 +192,11 @@ if (ENABLE_SUNDIALS)
 # Use find_package to get Sundials
 if (ENABLE_SUNDIALS)
   set(SUNDIALS_DIR "${sundials_DIR}")
-  find_package(SUNDIALS REQUIRED NO_DEFAULT_PATH
-    COMPONENTS kinsol nvecparallel nvecmpiplusx nvecserial 
-    PATHS ${sundials_DIR}/lib64/cmake/sundials ${sundials_DIR}/lib/cmake/sundials)
+  find_package(SUNDIALS REQUIRED
+    COMPONENTS kinsol nvecparallel nvecmpiplusx nvecserial )
   if(SUNDIALS_FOUND)
-    list(APPEND SPHERAL_BLT_DEPENDS SUNDIALS::kinsol_static SUNDIALS::nvecparallel_static SUNDIALS::nvecmpiplusx_static SUNDIALS::nvecserial_static)
-    list(APPEND SPHERAL_FP_TPLS SUNDIALS::kinsol_static SUNDIALS::nvecparallel_static SUNDIALS::nvecmpiplusx_static SUNDIALS::nvecserial_static)
+    list(APPEND SPHERAL_BLT_DEPENDS SUNDIALS::kinsol SUNDIALS::nvecparallel SUNDIALS::nvecmpiplusx SUNDIALS::nvecserial)
+    list(APPEND SPHERAL_FP_TPLS SUNDIALS::kinsol SUNDIALS::nvecparallel SUNDIALS::nvecmpiplusx SUNDIALS::nvecserial)
     list(APPEND SPHERAL_FP_DIRS ${sundials_DIR})
     message("Found SUNDIALS External Package")
   endif()
