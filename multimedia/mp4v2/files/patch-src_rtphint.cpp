src/rtphint.cpp:348:32: error: comparison between pointer and integer ('const char *' and 'int')
                    if (pSlash != '\0') {
                        ~~~~~~ ^  ~~~~

--- src/rtphint.cpp.orig	2012-05-20 22:11:53 UTC
+++ src/rtphint.cpp
@@ -339,7 +339,7 @@ void MP4RtpHintTrack::GetPayload(
                 pSlash = strchr(pSlash, '/');
                 if (pSlash != NULL) {
                     pSlash++;
-                    if (pSlash != '\0') {
+                    if (*pSlash != '\0') {
                         length = (uint32_t)strlen(pRtpMap) - (pSlash - pRtpMap);
                         *ppEncodingParams = (char *)MP4Calloc(length + 1);
                         strncpy(*ppEncodingParams, pSlash, length);
