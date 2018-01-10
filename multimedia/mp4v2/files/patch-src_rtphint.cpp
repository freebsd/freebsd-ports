src/rtphint.cpp:348:32: error: comparison between pointer and integer ('const char *' and 'int')
                    if (pSlash != '\0') {
                        ~~~~~~ ^  ~~~~

--- src/rtphint.cpp.orig	2009-07-13 23:07:12 UTC
+++ src/rtphint.cpp
@@ -345,7 +345,7 @@ void MP4RtpHintTrack::GetPayload(
                 pSlash = strchr(pSlash, '/');
                 if (pSlash != NULL) {
                     pSlash++;
-                    if (pSlash != '\0') {
+                    if (*pSlash != '\0') {
                         length = strlen(pRtpMap) - (pSlash - pRtpMap);
                         *ppEncodingParams = (char *)MP4Calloc(length + 1);
                         strncpy(*ppEncodingParams, pSlash, length);
