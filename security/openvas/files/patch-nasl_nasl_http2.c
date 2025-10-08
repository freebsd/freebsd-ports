--- nasl/nasl_http2.c	2025-10-07 22:47:47.850601000 -0700
+++ nasl/nasl_http2.c	2025-10-07 22:49:19.267011000 -0700
@@ -366,7 +366,7 @@
       curl_easy_setopt (handle, CURLOPT_CUSTOMREQUEST, "DELETE");
       break;
     case HEAD:
-      curl_easy_setopt (handle, CURLOPT_NOBODY, 1);
+      curl_easy_setopt (handle, CURLOPT_NOBODY, 1L);
       break;
     case PUT:
       curl_easy_setopt (handle, CURLOPT_CUSTOMREQUEST, "PUT");
@@ -377,7 +377,7 @@
         }
       break;
     case GET:
-      curl_easy_setopt (handle, CURLOPT_HTTPGET, 1);
+      curl_easy_setopt (handle, CURLOPT_HTTPGET, 1L);
       break;
     case POST:
       // Set body. POST is set automatically with this options
