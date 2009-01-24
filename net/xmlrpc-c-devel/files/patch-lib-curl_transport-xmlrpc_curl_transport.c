--- lib/curl_transport/xmlrpc_curl_transport.c.old	2008-11-12 13:05:29.000000000 +0200
+++ lib/curl_transport/xmlrpc_curl_transport.c	2008-11-12 13:05:38.000000000 +0200
@@ -557,7 +557,7 @@
             curl_easy_setopt(curlSessionP, CURLOPT_SSLENGINE,
                              curlSetupP->sslEngine);
         if (curlSetupP->sslEngineDefault)
-            curl_easy_setopt(curlSessionP, CURLOPT_SSLENGINE_DEFAULT);
+            curl_easy_setopt(curlSessionP, CURLOPT_SSLENGINE_DEFAULT, 1);
         if (curlSetupP->sslVersion != XMLRPC_SSLVERSION_DEFAULT)
             curl_easy_setopt(curlSessionP, CURLOPT_SSLVERSION,
                              curlSetupP->sslVersion);
