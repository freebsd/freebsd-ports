--- cmake/SetFreeRDPCMakeInstallDir.cmake.orig	2024-04-22 09:26:59 UTC
+++ cmake/SetFreeRDPCMakeInstallDir.cmake
@@ -1,7 +1,3 @@ function(SetFreeRDPCMakeInstallDir SETVAR subdir)
 function(SetFreeRDPCMakeInstallDir SETVAR subdir)
-	if(FREEBSD)
-		set(${SETVAR} "${CMAKE_INSTALL_DATAROOTDIR}/cmake/Modules/${subdir}" PARENT_SCOPE)
-	else()
-		set(${SETVAR} "${CMAKE_INSTALL_LIBDIR}/cmake/${subdir}" PARENT_SCOPE)
-	endif()
+	set(${SETVAR} "${CMAKE_INSTALL_LIBDIR}/cmake/${subdir}" PARENT_SCOPE)
 endfunction()
