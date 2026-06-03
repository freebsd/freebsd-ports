--- src/3rdparty/chromium/components/download/public/common/download_stats.h.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/components/download/public/common/download_stats.h
@@ -145,7 +145,7 @@ enum DownloadCountTypes {
 
 // Enum for in-progress download DB, used in histogram
 // "Download.InProgressDB.Counts".
-enum InProgressDBCountTypes {
+enum InProgressDBCountTypes : uint8_t {
   // Count of initialization attempts.
   kInitializationCount = 0,
 
