--- src/url.cc.old	2009-01-24 15:50:40.000000000 +0200
+++ src/url.cc	2009-01-24 15:51:07.000000000 +0200
@@ -75,7 +75,7 @@
 
     if (only_header)
     {
-        curl_easy_setopt(curl_handle, CURLOPT_NOBODY);
+        curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 1);
         curl_easy_setopt(curl_handle, CURLOPT_HEADERFUNCTION, URL::dl);
         curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, 
                          (void *)buffer.getPtr());
