--- base/files/drive_info_posix.cc.orig	2024-11-16 12:20:41 UTC
+++ base/files/drive_info_posix.cc
@@ -28,7 +28,7 @@ DriveInfo& DriveInfo::operator=(DriveInfo&&) = default
 
 std::optional<DriveInfo> GetFileDriveInfo(const FilePath& file_path) {
   DriveInfo drive_info;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   drive_info.has_seek_penalty = false;
   return drive_info;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
