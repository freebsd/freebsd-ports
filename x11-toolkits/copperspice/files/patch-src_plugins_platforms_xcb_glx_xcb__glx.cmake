--- src/plugins/platforms/xcb/glx/xcb_glx.cmake.orig	2022-02-17 11:21:35 UTC
+++ src/plugins/platforms/xcb/glx/xcb_glx.cmake
@@ -51,5 +51,5 @@ if(BUILD_PLATFORMS_XCB_PLUGIN AND XCB_GLX_LIB)
       -DXCB_USE_XINPUT2
    )
 
-   install(TARGETS CsGuiXcb_Glx DESTINATION ${CMAKE_INSTALL_LIBDIR})
+   install(TARGETS CsGuiXcb_Glx DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/xcbglintegrations)
 endif()
