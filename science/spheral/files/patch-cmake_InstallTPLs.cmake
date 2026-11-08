-- Adjust Spheral's third-party library discovery for FreeBSD packages.
-- Upstream hard-codes NO_DEFAULT_PATH with per-project subdirectories, while
-- FreeBSD installs CMake config files into standard prefix paths and provides
-- shared SUNDIALS targets. Also make PolyClipper install under a subdirectory
-- and set the correct Boost library variant flags.

--- cmake/InstallTPLs.cmake.orig	2026-06-23 16:46:22 UTC
+++ cmake/InstallTPLs.cmake
@@ -73,7 +73,7 @@ if (NOT polyclipper_DIR)
   list(APPEND SPHERAL_BLT_DEPENDS PolyClipperAPI)
   install(TARGETS PolyClipperAPI
     EXPORT spheral_cxx-targets
-    DESTINATION lib/cmake)
+    DESTINATION lib/cmake/spheral_cxx)
   set_target_properties(PolyClipperAPI PROPERTIES EXPORT_NAME spheral::PolyClipperAPI)
   message("Found PolyClipper External Package.")
 else()
@@ -88,8 +88,12 @@ set(SPHERAL_FP_DIRS )
 set(SPHERAL_FP_TPLS )
 set(SPHERAL_FP_DIRS )
 
+# Packages on FreeBSD install cmake configs directly into lib/cmake/,
+# not in a per-package subdirectory, so we need to include that path.
+list(PREPEND CMAKE_PREFIX_PATH "${axom_DIR}/lib/cmake")
+
 # Use find_package to get axom (which brings in fmt) and patch fmt
-find_package(axom REQUIRED NO_DEFAULT_PATH PATHS ${axom_DIR}/lib/cmake)
+find_package(axom REQUIRED)
 list(APPEND SPHERAL_BLT_DEPENDS axom)
 list(APPEND SPHERAL_FP_TPLS axom)
 list(APPEND SPHERAL_FP_DIRS ${axom_DIR}/lib/cmake)
@@ -106,7 +110,7 @@ message("---------------------------------------------
 
 message("-----------------------------------------------------------------------------")
 # Use find_package to get adiak
-find_package(adiak REQUIRED NO_DEFAULT_PATH PATHS ${adiak_DIR}/lib/cmake/adiak)
+find_package(adiak REQUIRED)
 if(adiak_FOUND)
   list(APPEND SPHERAL_BLT_DEPENDS adiak::adiak)
   list(APPEND SPHERAL_FP_TPLS adiak)
@@ -116,7 +120,7 @@ message("---------------------------------------------
 
 message("-----------------------------------------------------------------------------")
 # Use find_package to get polytope
-find_package(polytope NO_DEFAULT_PATH PATHS ${polytope_DIR}/lib/cmake)
+find_package(polytope REQUIRED)
 if(POLYTOPE_FOUND)
   list(APPEND SPHERAL_BLT_DEPENDS polytope)
   list(APPEND SPHERAL_FP_TPLS polytope)
@@ -149,7 +153,7 @@ if (SPHERAL_ENABLE_TIMERS)
     # Only save if it does not exists already
     set(CONFIG_CALIPER_DIR "${caliper_DIR}" CACHE PATH "Configuration Caliper directory")
   endif()
-  find_package(caliper REQUIRED NO_DEFAULT_PATH PATHS ${caliper_DIR}/share/cmake/caliper)
+  find_package(caliper REQUIRED PATHS ${caliper_DIR}/share/cmake/caliper)
   if(caliper_FOUND)
     list(APPEND SPHERAL_BLT_DEPENDS caliper)
     list(APPEND SPHERAL_FP_TPLS caliper)
@@ -162,7 +166,7 @@ if(NOT SPHERAL_EXTERNAL_INSTALL)
 # HDF5
 
 if(NOT SPHERAL_EXTERNAL_INSTALL)
-  find_package(hdf5 REQUIRED NO_DEFAULT_PATH PATHS ${hdf5_DIR})
+  find_package(hdf5 REQUIRED)
   message("Found HDF5 External Package.")
   list(APPEND SPHERAL_FP_TPLS hdf5)
   list(APPEND SPHERAL_FP_DIRS ${hdf5_DIR})
@@ -172,22 +176,24 @@ message("---------------------------------------------
 endif()
 
 message("-----------------------------------------------------------------------------")
-find_package(RAJA REQUIRED NO_DEFAULT_PATH PATHS ${raja_DIR})
+find_package(RAJA REQUIRED)
 if (RAJA_FOUND)
   message("Found RAJA External Package.")
 endif()
 
 message("-----------------------------------------------------------------------------")
-find_package(umpire REQUIRED NO_DEFAULT_PATH PATHS ${umpire_DIR})
+find_package(umpire REQUIRED)
 if (umpire_FOUND)
   message("Found umpire External Package.")
 endif()
 
 message("-----------------------------------------------------------------------------")
 # Chai
-find_package(chai REQUIRED NO_DEFAULT_PATH PATHS ${chai_DIR})
-if(chai_FOUND)
-  message("Found chai External Package.")
+if(USE_EXTERNAL_CHAI)
+  find_package(chai REQUIRED)
+  if(chai_FOUND)
+    message("Found chai External Package.")
+  endif()
 endif()
 
 list(APPEND SPHERAL_BLT_DEPENDS chai camp RAJA umpire)
@@ -198,13 +204,12 @@ if (SPHERAL_ENABLE_SUNDIALS)
 # Use find_package to get Sundials
 if (SPHERAL_ENABLE_SUNDIALS)
   set(SUNDIALS_DIR "${sundials_DIR}")
-  find_package(SUNDIALS REQUIRED NO_DEFAULT_PATH
-    COMPONENTS kinsol nvecparallel nvecmpiplusx nvecserial
-    PATHS ${sundials_DIR}/lib64/cmake/sundials ${sundials_DIR}/lib/cmake/sundials)
+  find_package(SUNDIALS REQUIRED
+    COMPONENTS kinsol nvecparallel nvecmpiplusx nvecserial)
   if(SUNDIALS_FOUND)
     set(SUNDIAL_LIBS kinsol nvecparallel nvecmpiplusx nvecserial)
     foreach(_lib ${SUNDIAL_LIBS})
-      list(APPEND SPHERAL_BLT_DEPENDS SUNDIALS::${_lib}_static)
+      list(APPEND SPHERAL_BLT_DEPENDS SUNDIALS::${_lib})
     endforeach()
     list(APPEND SPHERAL_FP_TPLS SUNDIALS)
     list(APPEND SPHERAL_FP_DIRS ${sundials_DIR})
@@ -214,6 +219,9 @@ if(NOT SPHERAL_EXTERNAL_INSTALL)
 
 message("-----------------------------------------------------------------------------")
 if(NOT SPHERAL_EXTERNAL_INSTALL)
+  set(Boost_USE_DEBUG_RUNTIME OFF)
+  set(Boost_USE_STATIC_LIBS OFF)
+  set(Boost_USE_MULTITHREADED ON)
   find_package(Boost REQUIRED NO_DEFAULT_PATH COMPONENTS filesystem PATHS ${boost_DIR})
   if(Boost_FOUND)
     list(APPEND SPHERAL_BLT_DEPENDS Boost::filesystem)
@@ -244,7 +252,11 @@ endforeach()
   endif()
   list(APPEND SPHERAL_BLT_DEPENDS ${lib})
 endforeach()
-blt_convert_to_system_includes(TARGETS "${SPHERAL_BLT_DEPENDS}")
+foreach(_dep ${SPHERAL_BLT_DEPENDS})
+  if(TARGET ${_dep})
+    blt_convert_to_system_includes(TARGET ${_dep})
+  endif()
+endforeach()
 # Note: SPHERAL_BLT_DEPENDS is made global after this in SetupSpheral.cmake
 
 # This calls LLNLSpheralInstallTPLs.cmake
