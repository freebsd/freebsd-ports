--- cmake/admFFmpegBuild.cmake.orig
+++ cmake/admFFmpegBuild.cmake
@@ -209,9 +209,9 @@ add_library(ADM_libavformat UNKNOWN IMPO
 set_property(TARGET ADM_libavformat PROPERTY IMPORTED_LOCATION "${FFMPEG_BINARY_DIR}/libavformat/${LIBAVFORMAT_LIB}")
 install(${FFMPEG_SHLIB_INSTALL_TYPE} "${FFMPEG_BINARY_DIR}/libavformat/${LIBAVFORMAT_LIB}" DESTINATION "${FFMPEG_INSTALL_DIR}")
 
-include_directories("${FFMPEG_SOURCE_DIR}")
-include_directories("${FFMPEG_SOURCE_DIR}/libavutil")
-include_directories("${FFMPEG_SOURCE_DIR}/libpostproc")
+include_directories(BEFORE "${FFMPEG_SOURCE_DIR}/libpostproc")
+include_directories(BEFORE "${FFMPEG_SOURCE_DIR}/libavutil")
+include_directories(BEFORE "${FFMPEG_SOURCE_DIR}")
 
 # Clean FFmpeg
 add_custom_target(cleanffmpeg
