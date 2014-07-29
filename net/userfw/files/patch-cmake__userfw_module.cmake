--- ./cmake/userfw_module.cmake.orig	2013-03-29 14:22:50.000000000 +0000
+++ ./cmake/userfw_module.cmake	2014-07-29 09:30:53.000000000 +0100
@@ -11,7 +11,7 @@
 	add_custom_target(userfw_${modname} ALL
 		DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/userfw_${modname}.ko")
 
-	install(CODE "execute_process(COMMAND make install \"KMODDIR=${KMODDIR}\" \"PREFIX=${CMAKE_INSTALL_PREFIX}\"
+	install(CODE "execute_process(COMMAND make install \"KMODDIR=${KMODDIR}\" \"PREFIX=\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}\"
 		WORKING_DIRECTORY \"${CMAKE_CURRENT_SOURCE_DIR}\")")
 endfunction(declare_userfw_module)
 
@@ -28,6 +28,6 @@
 	add_custom_target(userfw_${modname} ALL
 		DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${filename}.ko")
 
-	install(CODE "execute_process(COMMAND make install \"KMODDIR=${KMODDIR}\" \"PREFIX=${CMAKE_INSTALL_PREFIX}\"
+	install(CODE "execute_process(COMMAND make install \"KMODDIR=${KMODDIR}\" \"PREFIX=\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}\"
 		WORKING_DIRECTORY \"${CMAKE_CURRENT_SOURCE_DIR}\")")
 endfunction(declare_userfw_module_with_name)
