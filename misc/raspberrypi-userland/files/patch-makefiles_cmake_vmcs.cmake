--- makefiles/cmake/vmcs.cmake.orig	2016-10-24 19:59:54 UTC
+++ makefiles/cmake/vmcs.cmake
@@ -57,10 +57,6 @@ configure_file (
 #        DESTINATION ${VMCS_INSTALL_PREFIX}/sbin
 #        PERMISSIONS OWNER_WRITE WORLD_READ)
 
-# provide hello_pi demos
-install(DIRECTORY host_applications/linux/apps/hello_pi
-        DESTINATION ${VMCS_INSTALL_PREFIX}/src)
-
 # provide header files
 #install(DIRECTORY host_applications/linux/libs/bcm_host/include
 #        DESTINATION ${VMCS_INSTALL_PREFIX}/)
