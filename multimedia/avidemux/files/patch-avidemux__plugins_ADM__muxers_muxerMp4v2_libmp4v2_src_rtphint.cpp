--- avidemux_plugins/ADM_muxers/muxerMp4v2/libmp4v2/src/rtphint.cpp.orig	2016-01-29 09:47:25.000000000 +0100
+++ avidemux_plugins/ADM_muxers/muxerMp4v2/libmp4v2/src/rtphint.cpp	2018-08-01 09:39:54.771441000 +0200
@@ -339,7 +339,7 @@
                 pSlash = strchr(pSlash, '/');
                 if (pSlash != NULL) {
                     pSlash++;
-                    if (pSlash != '\0') {
+                    if (*pSlash) {
                         length = (uint32_t)strlen(pRtpMap) - (pSlash - pRtpMap);
                         *ppEncodingParams = (char *)MP4Calloc(length + 1);
                         strncpy(*ppEncodingParams, pSlash, length);
