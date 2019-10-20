--- Curl.xs.orig	2014-02-21 16:08:30 UTC
+++ Curl.xs
@@ -18,6 +18,10 @@
 #include <curl/easy.h>
 #include <curl/multi.h>
 
+#ifdef CURLINC_MULTI_H
+#define __CURL_MULTI_H
+#endif
+
 #define header_callback_func writeheader_callback_func
 
 /* Do a favor for older perl versions */
@@ -38,6 +42,7 @@ typedef enum {
     SLIST_HTTPHEADER = 0,
     SLIST_QUOTE,
     SLIST_POSTQUOTE,
+    SLIST_CONNECT_TO,
 #ifdef CURLOPT_RESOLVE
     SLIST_RESOLVE,
 #endif
@@ -73,7 +78,7 @@ typedef struct {
 #ifdef __CURL_MULTI_H
     struct CURLM *curlm;
 #else
-    struct void *curlm;
+    void *curlm;
 #endif
 } perl_curl_multi;
 
@@ -129,6 +134,10 @@ slist_index(int option)
         case CURLOPT_POSTQUOTE:
             return SLIST_POSTQUOTE;
             break;
+        case CURLOPT_CONNECT_TO:
+            return SLIST_CONNECT_TO;
+            break;
+
 #ifdef CURLOPT_RESOLVE
         case CURLOPT_RESOLVE:
             return SLIST_RESOLVE;
@@ -754,6 +763,7 @@ curl_easy_setopt(self, option, value, push=0)
             case CURLOPT_HTTPHEADER:
             case CURLOPT_QUOTE:
             case CURLOPT_POSTQUOTE:
+            case CURLOPT_CONNECT_TO:
 #ifdef CURLOPT_RESOLVE
             case CURLOPT_RESOLVE:
 #endif
