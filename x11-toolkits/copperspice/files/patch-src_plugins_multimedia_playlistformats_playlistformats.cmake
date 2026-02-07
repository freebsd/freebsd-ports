--- src/plugins/multimedia/playlistformats/playlistformats.cmake.orig	2022-02-17 11:15:59 UTC
+++ src/plugins/multimedia/playlistformats/playlistformats.cmake
@@ -24,4 +24,4 @@ target_compile_definitions(CsMultimedia_m3u
    -DQT_PLUGIN
 )
 
-install(TARGETS CsMultimedia_m3u DESTINATION ${CMAKE_INSTALL_LIBDIR})
+install(TARGETS CsMultimedia_m3u DESTINATION ${CMAKE_INSTALL_LIBDIR}${CS_NAMESPACE_DIRECTORY}/mediaservices)
