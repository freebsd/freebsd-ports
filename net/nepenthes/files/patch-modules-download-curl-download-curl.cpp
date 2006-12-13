--- modules/download-curl/download-curl.cpp.orig	Tue Dec  5 15:53:24 2006
+++ modules/download-curl/download-curl.cpp	Tue Dec  5 15:54:09 2006
@@ -230,7 +230,9 @@
 				 down->getDownloadUrl()->getPort(),
 				 down->getDownloadUrl()->getPath().c_str());
 //        string auth = down->getDownloadUrl()->getUser() + ":" + down->getDownloadUrl()->getPass();
+#if LIBCURL_VERSION_NUM < 0x071000
 		curl_easy_setopt(pCurlHandle, CURLOPT_SOURCE_USERPWD,(char *)down->getDownloadUrl()->getAuth().c_str());
+#endif
 		curl_easy_setopt(pCurlHandle, CURLOPT_USERPWD,(char *)down->getDownloadUrl()->getAuth().c_str());
 		curl_easy_setopt(pCurlHandle, CURLOPT_URL			, url);
 		curl_easy_setopt(pCurlHandle, CURLOPT_FTP_RESPONSE_TIMEOUT, 120);	// 2 min ftp timeout
