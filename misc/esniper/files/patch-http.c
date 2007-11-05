--- http.c.orig	Wed Oct 31 15:13:04 2007
+++ http.c	Wed Oct 31 15:13:39 2007
@@ -51,7 +51,7 @@
 static int initCurlStuffFailed(void);
 
 #ifdef NEED_CURL_EASY_STRERROR
-static const char *curl_easy_strerror(CURLcode error);
+const char *curl_easy_strerror(CURLcode error);
 #endif
 
 /* Set auction error with full libcurl details */
@@ -409,7 +409,7 @@
 	"Requested FTP SSL level failed", /* CURLE_FTP_SSL_FAILED */
 };
 
-static const char *
+const char *
 curl_easy_strerror(CURLcode error)
 {
 	if (error < 0 || error >= CURL_LAST ||
