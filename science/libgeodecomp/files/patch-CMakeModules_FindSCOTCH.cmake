--- CMakeModules/FindSCOTCH.cmake.orig	2020-09-20 01:42:12 UTC
+++ CMakeModules/FindSCOTCH.cmake
@@ -121,6 +121,7 @@ endif()
 set(SCOTCH_LIBRARIES ${SCOTCH_LIBRARIES} ${PTSCOTCHERR_LIBRARY})
 
 # Try compiling and running test program
+set(DOLFIN_SKIP_BUILD_TESTS 1)
 if (DOLFIN_SKIP_BUILD_TESTS)
   set(SCOTCH_TEST_RUNS TRUE)
 elseif (SCOTCH_INCLUDE_DIRS AND SCOTCH_LIBRARIES)
