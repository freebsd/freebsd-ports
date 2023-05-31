--- source/encoders/ffmpeg/amf.cpp.orig	2023-05-29 23:23:46 UTC
+++ source/encoders/ffmpeg/amf.cpp
@@ -136,7 +136,7 @@ bool streamfx::encoder::ffmpeg::amf::is_available()
 #else
 	std::filesystem::path lib_name = std::filesystem::u8path("amfrt32.dll");
 #endif
-#elif defined(D_PLATFORM_LINUX)
+#elif defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 #if defined(D_PLATFORM_64BIT)
 	std::filesystem::path lib_name = std::filesystem::u8path("libamfrt64.so.1");
 #else
