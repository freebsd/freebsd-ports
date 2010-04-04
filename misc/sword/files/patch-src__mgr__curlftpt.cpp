--- ./src/mgr/curlftpt.cpp.orig	2010-04-04 01:26:26.000000000 -0400
+++ ./src/mgr/curlftpt.cpp	2010-04-04 01:26:02.000000000 -0400
@@ -124,6 +124,7 @@
 
 
 CURLFTPTransport::~CURLFTPTransport() {
+	curl_easy_setopt(session, CURLOPT_PROGRESSDATA, (void*)NULL);
 	curl_easy_cleanup(session);
 }
 
