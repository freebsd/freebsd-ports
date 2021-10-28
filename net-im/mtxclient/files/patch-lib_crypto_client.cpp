--- lib/crypto/client.cpp.orig	2021-10-28 17:44:28 UTC
+++ lib/crypto/client.cpp
@@ -37,15 +37,15 @@ static const std::array olmErrorStrings{
 
 };
 
-OlmErrorCode
+mtx::crypto::OlmErrorCode
 olm_exception::ec_from_string(std::string_view error)
 {
         for (size_t i = 0; i < olmErrorStrings.size(); i++) {
                 if (olmErrorStrings[i] == error)
-                        return static_cast<OlmErrorCode>(i);
+                        return static_cast<mtx::crypto::OlmErrorCode>(i);
         }
 
-        return OlmErrorCode::UNKNOWN_ERROR;
+        return mtx::crypto::OlmErrorCode::UNKNOWN_ERROR;
 }
 
 void
