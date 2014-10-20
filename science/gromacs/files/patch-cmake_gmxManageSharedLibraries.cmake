--- cmake/gmxManageSharedLibraries.cmake.orig	2014-06-17 15:14:18.000000000 +0000
+++ cmake/gmxManageSharedLibraries.cmake
@@ -39,7 +39,7 @@
 ########################################################################
 # Determine the defaults (this block has no effect if the variables have
 # already been set)
-if((APPLE OR CYGWIN OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux|.*BSD|GNU") AND NOT GMX_BUILD_MDRUN_ONLY)
+if((APPLE OR CYGWIN OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux|.*BSD|DragonFly") AND NOT GMX_BUILD_MDRUN_ONLY)
     # Maybe Solaris should be here? Patch this if you know!
     SET(SHARED_LIBS_DEFAULT ON)
 elseif(WIN32 OR ${CMAKE_SYSTEM_NAME} MATCHES "BlueGene")
