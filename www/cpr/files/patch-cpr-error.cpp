--- cpr/error.cpp.orig	2017-11-01 21:56:02 UTC
+++ cpr/error.cpp
@@ -22,8 +22,10 @@ ErrorCode Error::getErrorCodeForCurlErro
             return ErrorCode::OPERATION_TIMEDOUT;
         case CURLE_SSL_CONNECT_ERROR:
             return ErrorCode::SSL_CONNECT_ERROR;
+#if LIBCURL_VERSION_NUM < 0x073e00
         case CURLE_PEER_FAILED_VERIFICATION:
             return ErrorCode::SSL_REMOTE_CERTIFICATE_ERROR;
+#endif
         case CURLE_GOT_NOTHING:
             return ErrorCode::EMPTY_RESPONSE;
         case CURLE_SSL_ENGINE_NOTFOUND:
@@ -38,8 +40,13 @@ ErrorCode Error::getErrorCodeForCurlErro
             return ErrorCode::SSL_LOCAL_CERTIFICATE_ERROR;
         case CURLE_SSL_CIPHER:
             return ErrorCode::GENERIC_SSL_ERROR;
+#if LIBCURL_VERSION_NUM >= 0x073e00
+        case CURLE_PEER_FAILED_VERIFICATION:
+            return ErrorCode::SSL_REMOTE_CERTIFICATE_ERROR;
+#else
         case CURLE_SSL_CACERT:
             return ErrorCode::SSL_CACERT_ERROR;
+#endif
         case CURLE_USE_SSL_FAILED:
             return ErrorCode::GENERIC_SSL_ERROR;
         case CURLE_SSL_ENGINE_INITFAILED:
