--- media/gpu/chromeos/platform_video_frame_utils.cc.orig	2026-04-09 06:05:42 UTC
+++ media/gpu/chromeos/platform_video_frame_utils.cc
@@ -69,7 +69,7 @@ static std::unique_ptr<ui::GbmDevice> CreateGbmDevice(
     const base::FilePath dev_path(FILE_PATH_LITERAL(
         base::StrCat({drm_node_file_prefix, base::NumberToString(i)})));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
     const bool is_render_node = drm_node_file_prefix.contains("render");
 
     // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
@@ -179,7 +179,7 @@ class GbmDeviceWrapper {
             switches::kRenderNodeOverride)});
     for (const auto& dev_path : dev_paths) {
       if (!dev_path.empty()) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_V4L2_CODEC)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_V4L2_CODEC)
         const bool is_render_node = dev_path.value().contains("render");
 
         // TODO(b/313513760): don't guard base::File::FLAG_WRITE behind
