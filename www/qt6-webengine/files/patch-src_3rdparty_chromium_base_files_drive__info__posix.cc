--- src/3rdparty/chromium/base/files/drive_info_posix.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/files/drive_info_posix.cc
@@ -24,7 +24,7 @@ std::optional<DriveInfo> GetFileDriveInfo(const FilePa
 
 std::optional<DriveInfo> GetFileDriveInfo(const FilePath& file_path) {
   DriveInfo drive_info;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   drive_info.has_seek_penalty = false;
   return drive_info;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
