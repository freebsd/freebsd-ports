--- src/plugins/printerdrivers/cups/cupsprinter.cmake.orig	2022-02-17 11:23:12 UTC
+++ src/plugins/printerdrivers/cups/cupsprinter.cmake
@@ -37,6 +37,6 @@ if(Cups_FOUND)
 
    function_generate_resources(CsPrinterDriverCups)
 
-   install(TARGETS CsPrinterDriverCups DESTINATION ${CMAKE_INSTALL_LIBDIR})
+   install(TARGETS CsPrinterDriverCups DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/platforms)
 endif()
 
