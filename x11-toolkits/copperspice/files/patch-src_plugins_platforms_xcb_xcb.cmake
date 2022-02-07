--- src/plugins/platforms/xcb/xcb.cmake.orig	2022-02-17 11:13:33 UTC
+++ src/plugins/platforms/xcb/xcb.cmake
@@ -28,6 +28,6 @@ if(BUILD_PLATFORMS_XCB_PLUGIN)
       -DXCB_USE_XINPUT2
    )
 
-   install(TARGETS CsGuiXcb DESTINATION ${CMAKE_INSTALL_LIBDIR})
+   install(TARGETS CsGuiXcb DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/platforms)
 endif()
 
