--- src/HttpCurl.cpp.orig	Mon Mar 21 22:11:12 2005
+++ src/HttpCurl.cpp	Mon Mar 21 22:11:37 2005
@@ -113,7 +113,7 @@
 
     curl_version_info_data *curl_info;
     curl_info = curl_version_info(CURLVERSION_NOW);
-    curl_protocols = curl_info->protocols;
+    curl_protocols = (const char **)curl_info->protocols;
 
     FD_ZERO(&fdread);
     FD_ZERO(&fdwrite);
