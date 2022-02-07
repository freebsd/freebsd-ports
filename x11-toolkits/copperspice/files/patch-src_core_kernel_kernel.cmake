--- src/core/kernel/kernel.cmake.orig	2022-02-17 22:27:19 UTC
+++ src/core/kernel/kernel.cmake
@@ -150,6 +150,7 @@ target_sources(CsCore
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/csobject_debug.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kernel/csobject_private.cpp
 )
+target_compile_definitions(CsCore PRIVATE CS_DEFAULT_PLUGINPATH="${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}")
 
 if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_sources(CsCore
@@ -194,4 +195,4 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
       ${CMAKE_CURRENT_SOURCE_DIR}/kernel/qsystemsemaphore_win.cpp
    )
 
-endif()
\ No newline at end of file
+endif()
