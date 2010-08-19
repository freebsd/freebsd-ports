--- http.c.orig	2010-08-16 13:42:14.099356738 +0200
+++ http.c	2010-08-16 13:42:58.186459428 +0200
@@ -52,7 +52,7 @@ static size_t WriteMemoryCallback(void *
 static int initCurlStuffFailed(void);
 
 #ifdef NEED_CURL_EASY_STRERROR
-static const char *curl_easy_strerror(CURLcode error);
+const char *curl_easy_strerror(CURLcode error);
 #endif
 
 /* Set auction error with full libcurl details */
@@ -517,7 +517,7 @@ static const char *curlErrorTable[] = {
 	"Requested FTP SSL level failed", /* CURLE_FTP_SSL_FAILED */
 };
 
-static const char *
+const char *
 curl_easy_strerror(CURLcode error)
 {
 	if (error < 0 || error >= CURL_LAST ||
