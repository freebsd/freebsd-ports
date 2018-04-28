--- ./cmake/modules/DBusMacros.cmake.bak	2010-12-15 19:50:32.015441170 +1000
+++ ./cmake/modules/DBusMacros.cmake	2010-12-15 19:52:27.213438681 +1000
@@ -26,6 +26,6 @@
         string(REGEX REPLACE "\\.service.*$" ".service" _output_file ${_i})
         set(_target ${CMAKE_CURRENT_BINARY_DIR}/${_output_file})
         configure_file(${_service_file} ${_target})
-        install(FILES ${_target} DESTINATION ${DATA_INSTALL_DIR}/dbus-1/services)
+        install(FILES ${_target} DESTINATION ${DBUS_SERVICES_INSTALL_DIR})
     endforeach (_i ${ARGN})
 endmacro(dbus_add_activation_service _sources)
