--- avidemux_plugins/ADM_muxers/muxerMp4v2/libmp4v2/src/rtphint.cpp.orig	2016-01-29 09:47:25.000000000 +0100
+++ avidemux_plugins/ADM_muxers/muxerMp4v2/libmp4v2/src/rtphint.cpp	2018-07-30 08:44:59.947567000 +0200
@@ -339,7 +339,7 @@
                 pSlash = strchr(pSlash, '/');
                 if (pSlash != NULL) {
                     pSlash++;
-                    if (pSlash != '\0') {
+                    if (*pSlash != '\0') {
                         length = (uint32_t)strlen(pRtpMap) - (pSlash - pRtpMap);
                         *ppEncodingParams = (char *)MP4Calloc(length + 1);
                         strncpy(*ppEncodingParams, pSlash, length);
