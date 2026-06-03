--- cmake/modules/DuneDoxygen.cmake.orig	2026-03-31 05:34:46 UTC
+++ cmake/modules/DuneDoxygen.cmake
@@ -134,7 +134,7 @@ macro(add_doxygen_target)
            # Manifest is generated when prefix was set at configuration time, otherwise is skipped
            LIST(APPEND CMAKE_INSTALL_MANIFEST_FILES ${CMAKE_INSTALL_FULL_DOCDIR}/doxygen/\${_basename})
          endforeach()
-         file(INSTALL \${doxygenfiles} DESTINATION ${CMAKE_INSTALL_DOCDIR}/doxygen)
-         message(STATUS \"Installed doxygen into ${CMAKE_INSTALL_DOCDIR}/doxygen\")")
+         file(INSTALL \${doxygenfiles} DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DOCDIR}/doxygen)
+         message(STATUS \"Installed doxygen into ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DOCDIR}/doxygen\")")
   endif()
 endmacro(add_doxygen_target)
