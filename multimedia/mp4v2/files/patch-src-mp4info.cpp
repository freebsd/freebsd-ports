--- src/mp4info.cpp.orig	2012-05-20 22:11:53 UTC
+++ src/mp4info.cpp
@@ -109,7 +109,7 @@ static char* PrintAudioInfo(
     const char* typeName = "Unknown";
     bool foundType = false;
     uint8_t type = 0;
-    const char *media_data_name;
+    const char *media_data_name = NULL;
 
     media_data_name = MP4GetTrackMediaDataName(mp4File, trackId);
 
@@ -306,7 +306,7 @@ static char* PrintVideoInfo(
     bool foundTypeName = false;
     const char* typeName = "Unknown";
 
-    const char *media_data_name;
+    const char *media_data_name = NULL;
     char originalFormat[8];
     char  oformatbuffer[32];
     originalFormat[0] = 0;
@@ -315,7 +315,7 @@ static char* PrintVideoInfo(
 
     media_data_name = MP4GetTrackMediaDataName(mp4File, trackId);
     // encv 264b
-    if (strcasecmp(media_data_name, "encv") == 0) {
+    if (media_data_name != NULL && strcasecmp(media_data_name, "encv") == 0) {
         if (MP4GetTrackMediaDataOriginalFormat(mp4File,
                                                trackId,
                                                originalFormat,
