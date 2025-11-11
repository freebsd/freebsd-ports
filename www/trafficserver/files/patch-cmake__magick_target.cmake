--- cmake/magick_target.cmake.orig	2025-01-29 14:00:25 UTC
+++ cmake/magick_target.cmake
@@ -15,6 +15,8 @@
 #
 #######################
 
+if(BUILD_MAGICK)
+
 if(ImageMagick_Magick++_FOUND AND NOT TARGET ImageMagick::Magick++)
   add_library(ImageMagick::Magick++ INTERFACE IMPORTED)
   target_include_directories(ImageMagick::Magick++ INTERFACE ${ImageMagick_Magick++_INCLUDE_DIRS})
@@ -40,4 +42,6 @@ if(ImageMagick_MagickCore_FOUND AND NOT TARGET ImageMa
   target_link_libraries(ImageMagick::MagickCore INTERFACE ${ImageMagick_LIBRARIES})
   target_compile_options(ImageMagick::MagickCore INTERFACE -fopenmp)
   target_compile_definitions(ImageMagick::MagickCore INTERFACE MAGICKCORE_HDRI_ENABLE=0 MAGICKCORE_QUANTUM_DEPTH=16)
+endif()
+
 endif()
