--- makefiles/cmake/vmcs.cmake.orig	2015-01-05 16:36:28 UTC
+++ makefiles/cmake/vmcs.cmake
@@ -55,10 +55,6 @@
 #        DESTINATION ${VMCS_INSTALL_PREFIX}/sbin
 #        PERMISSIONS OWNER_WRITE WORLD_READ)
 
-# provide hello_pi demos
-install(DIRECTORY host_applications/linux/apps/hello_pi
-        DESTINATION ${VMCS_INSTALL_PREFIX}/src)
-
 # provide header files
 #install(DIRECTORY host_applications/linux/libs/bcm_host/include
 #        DESTINATION ${VMCS_INSTALL_PREFIX}/)
