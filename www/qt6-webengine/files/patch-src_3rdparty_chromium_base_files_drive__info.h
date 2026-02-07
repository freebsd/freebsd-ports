--- src/3rdparty/chromium/base/files/drive_info.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/files/drive_info.h
@@ -48,7 +48,7 @@ struct BASE_EXPORT DriveInfo {
   std::optional<bool> has_seek_penalty;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Whether the drive is a removable drive.
   //
   // Note on macOS: that SSDs that are connected over USB that you can eject
