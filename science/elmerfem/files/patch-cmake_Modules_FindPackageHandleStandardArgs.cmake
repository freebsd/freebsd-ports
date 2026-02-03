--- cmake/Modules/FindPackageHandleStandardArgs.cmake.orig	2020-11-10 19:52:44 UTC
+++ cmake/Modules/FindPackageHandleStandardArgs.cmake
@@ -100,7 +100,6 @@
 #  License text for the above reference.)
 
 include(${CMAKE_CURRENT_LIST_DIR}/FindPackageMessage.cmake)
-include(${CMAKE_CURRENT_LIST_DIR}/CMakeParseArguments.cmake)
 
 # internal helper macro
 macro(_FPHSA_FAILURE_MESSAGE _msg)
