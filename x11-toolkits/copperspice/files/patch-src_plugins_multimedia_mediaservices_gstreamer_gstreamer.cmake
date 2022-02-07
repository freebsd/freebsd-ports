--- src/plugins/multimedia/mediaservices/gstreamer/gstreamer.cmake.orig	2022-02-17 11:16:53 UTC
+++ src/plugins/multimedia/mediaservices/gstreamer/gstreamer.cmake
@@ -284,7 +284,7 @@ if(WITH_MULTIMEDIA AND GStreamer_FOUND)
    set_target_properties(CsMultimedia_gst_camerabin    PROPERTIES PREFIX "")
    set_target_properties(CsMultimedia_gst_mediaplayer  PROPERTIES PREFIX "")
 
-   install(TARGETS CsMultimedia_gst_audiodecoder DESTINATION ${CMAKE_INSTALL_LIBDIR})
-   install(TARGETS CsMultimedia_gst_camerabin    DESTINATION ${CMAKE_INSTALL_LIBDIR})
-   install(TARGETS CsMultimedia_gst_mediaplayer  DESTINATION ${CMAKE_INSTALL_LIBDIR})
+   install(TARGETS CsMultimedia_gst_audiodecoder DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/mediaservices)
+   install(TARGETS CsMultimedia_gst_camerabin    DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/mediaservices)
+   install(TARGETS CsMultimedia_gst_mediaplayer  DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/mediaservices)
 endif()
