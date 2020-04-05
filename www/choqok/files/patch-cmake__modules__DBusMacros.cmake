--- cmake/modules/DBusMacros.cmake.orig	2020-02-05 11:49:13 UTC
+++ cmake/modules/DBusMacros.cmake
@@ -26,6 +26,6 @@ macro(dbus_add_activation_service _sources)
         string(REGEX REPLACE "\\.service.*$" ".service" _output_file ${_i})
         set(_target ${CMAKE_CURRENT_BINARY_DIR}/${_output_file})
         configure_file(${_service_file} ${_target})
-        install(FILES ${_target} DESTINATION ${DATA_INSTALL_DIR}/dbus-1/services)
+        install(FILES ${_target} DESTINATION ${DBUS_SERVICES_INSTALL_DIR})
     endforeach (_i ${ARGN})
 endmacro(dbus_add_activation_service _sources)
