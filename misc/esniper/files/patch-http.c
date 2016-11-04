--- http.c.orig	2016-10-30 21:16:41 UTC
+++ http.c
@@ -52,7 +52,7 @@ static size_t WriteMemoryCallback(void *
 static int initCurlStuffFailed(void);
 
 #ifdef NEED_CURL_EASY_STRERROR
-static const char *curl_easy_strerror(CURLcode error);
+const char *curl_easy_strerror(CURLcode error);
 #endif
 
 /* Set auction error with full libcurl details */
@@ -535,7 +535,7 @@ static const char *curlErrorTable[] = {
 	"Requested FTP SSL level failed", /* CURLE_FTP_SSL_FAILED */
 };
 
-static const char *
+const char *
 curl_easy_strerror(CURLcode error)
 {
 	if (error < 0 || error >= CURL_LAST ||
