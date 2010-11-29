--- src/youtube_video_url.cc.org	2010-04-04 05:23:31.000000000 +0900
+++ src/youtube_video_url.cc	2010-11-06 20:38:26.296613788 +0900
@@ -47,7 +47,7 @@
 #define YOUTUBE_URL_PARAMS_REGEXP   "var swfHTML.*\\;"
 #define YOUTUBE_URL_LOCATION_REGEXP "\nLocation: (http://[^\n]+)\n"
 #define YOUTUBE_URL_WATCH           "http://www.youtube.com/watch?v="
-#define YOUTUBE_URL_GET             "http://www.youtube.com/get_video?" 
+#define YOUTUBE_URL_GET             "http://www.youtube.com/get_video?asv=3&"
 #define YOUTUBE_URL_PARAM_VIDEO_ID  "video_id"
 #define YOUTUBE_URL_PARAM_T_REGEXP  ".*&t=([^&]+)&"
 #define YOUTUBE_URL_PARAM_T         "t"
