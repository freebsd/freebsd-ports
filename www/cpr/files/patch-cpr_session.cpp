--- cpr/session.cpp.orig	2018-07-18 20:02:06 UTC
+++ cpr/session.cpp
@@ -350,7 +350,7 @@ Response Session::Impl::Patch() {
 Response Session::Impl::Post() {
     auto curl = curl_->handle;
     if (curl) {
-        curl_easy_setopt(curl, CURLOPT_HTTPGET, 0L);
+        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
         curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);
     }
 
