--- source/encoders/handlers/amf_shared.cpp.orig	2022-06-19 17:00:02 UTC
+++ source/encoders/handlers/amf_shared.cpp
@@ -109,7 +109,7 @@ bool streamfx::encoder::ffmpeg::handler::amf::is_avail
 #else
 	std::filesystem::path lib_name = std::filesystem::u8path("amfrt32.dll");
 #endif
-#elif defined(D_PLATFORM_LINUX)
+#elif defined(D_PLATFORM_LINUX) || defined(D_PLATFORM_FREEBSD)
 #if defined(D_PLATFORM_64BIT)
 	std::filesystem::path lib_name = std::filesystem::u8path("libamfrt64.so.1");
 #else
