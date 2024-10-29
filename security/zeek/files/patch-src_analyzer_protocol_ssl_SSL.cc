--- src/analyzer/protocol/ssl/SSL.cc.orig	2024-10-04 22:44:09 UTC
+++ src/analyzer/protocol/ssl/SSL.cc
@@ -5,7 +5,6 @@
 #include <openssl/opensslv.h>
 
 #include "zeek/Reporter.h"
-#include "zeek/analyzer/Manager.h"
 #include "zeek/analyzer/protocol/ssl/events.bif.h"
 #include "zeek/analyzer/protocol/ssl/ssl_pac.h"
 #include "zeek/analyzer/protocol/ssl/tls-handshake_pac.h"
@@ -32,11 +31,11 @@ static inline T LSB(const T a) {
     return (a & 0xff);
 }
 
-static std::basic_string<unsigned char> fmt_seq(uint32_t num) {
-    std::basic_string<unsigned char> out(4, '\0');
+static std::string fmt_seq(uint32_t num) {
+    std::string out(4, '\0');
     out.reserve(13);
     uint32_t netnum = htonl(num);
-    out.append(reinterpret_cast<u_char*>(&netnum), 4);
+    out.append(reinterpret_cast<char*>(&netnum), 4);
     out.append(5, '\0');
     return out;
 }
@@ -266,13 +265,13 @@ bool SSL_Analyzer::TryDecryptApplicationData(int len, 
         // server write_key
         const u_char* s_wk = keys.data() + 32;
         // client IV
-        const u_char* c_iv = keys.data() + 64;
+        const char* c_iv = reinterpret_cast<const char*>(keys.data()) + 64;
         // server IV
-        const u_char* s_iv = keys.data() + 68;
+        const char* s_iv = reinterpret_cast<const char*>(keys.data()) + 68;
 
         // FIXME: should we change types here?
-        u_char* encrypted = (u_char*)data;
-        size_t encrypted_len = len;
+        char* encrypted = (char*)data;
+        int encrypted_len = len;
 
         if ( is_orig )
             c_seq++;
@@ -280,7 +279,7 @@ bool SSL_Analyzer::TryDecryptApplicationData(int len, 
             s_seq++;
 
         // AEAD nonce, length 12
-        std::basic_string<unsigned char> s_aead_nonce;
+        std::string s_aead_nonce;
         if ( is_orig )
             s_aead_nonce.assign(c_iv, 4);
         else
@@ -306,14 +305,14 @@ bool SSL_Analyzer::TryDecryptApplicationData(int len, 
 
         // FIXME: aes_256_gcm should not be hardcoded here ;)
         if ( is_orig )
-            EVP_DecryptInit(ctx, EVP_aes_256_gcm(), c_wk, s_aead_nonce.data());
+            EVP_DecryptInit(ctx, EVP_aes_256_gcm(), c_wk, reinterpret_cast<const u_char*>(s_aead_nonce.data()));
         else
-            EVP_DecryptInit(ctx, EVP_aes_256_gcm(), s_wk, s_aead_nonce.data());
+            EVP_DecryptInit(ctx, EVP_aes_256_gcm(), s_wk, reinterpret_cast<const u_char*>(s_aead_nonce.data()));
 
         EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, encrypted + encrypted_len);
 
         // AEAD tag
-        std::basic_string<unsigned char> s_aead_tag;
+        std::string s_aead_tag;
         if ( is_orig )
             s_aead_tag = fmt_seq(c_seq);
         else
@@ -330,8 +329,10 @@ bool SSL_Analyzer::TryDecryptApplicationData(int len, 
                                              16); // see OpenSSL manpage - 16 is the block size for the supported cipher
         int decrypted_len = 0;
 
-        EVP_DecryptUpdate(ctx, NULL, &decrypted_len, s_aead_tag.data(), s_aead_tag.size());
-        EVP_DecryptUpdate(ctx, decrypted.data(), &decrypted_len, (const u_char*)encrypted, encrypted_len);
+        EVP_DecryptUpdate(ctx, NULL, &decrypted_len, reinterpret_cast<const u_char*>(s_aead_tag.data()),
+                          s_aead_tag.size());
+        EVP_DecryptUpdate(ctx, decrypted.data(), &decrypted_len, reinterpret_cast<const u_char*>(encrypted),
+                          encrypted_len);
         assert(static_cast<decltype(decrypted.size())>(decrypted_len) <= decrypted.size());
         decrypted.resize(decrypted_len);
 
