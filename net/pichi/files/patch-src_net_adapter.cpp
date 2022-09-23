--- src/net/adapter.cpp.orig
+++ src/net/adapter.cpp
@@ -27,11 +27,12 @@
 #include <pichi/vo/messages.hpp>
 #include <pichi/vo/options.hpp>
 
-#ifdef DEPRECATED_RFC2818_CLASS
+#include <boost/version.hpp>
+#if BOOST_VERSION >= 107300
 #include <boost/asio/ssl/host_name_verification.hpp>
-#else  // DEPRECATED_RFC2818_CLASS
+#else  // BOOST_VERSION >= 107300
 #include <boost/asio/ssl/rfc2818_verification.hpp>
-#endif  // DEPRECATED_RFC2818_CLASS
+#endif  // BOOST_VERSION >= 107300
 
 using namespace std;
 namespace asio = boost::asio;
@@ -67,11 +68,11 @@ static auto createTlsContext(vo::TlsEgressOption const
     ctx.load_verify_file(*option.caFile_);
   else {
     ctx.set_default_verify_paths();
-#ifdef DEPRECATED_RFC2818_CLASS
+#if BOOST_VERSION >= 107300
     ctx.set_verify_callback(ssl::host_name_verification{option.serverName_.value_or(serverName)});
-#else   // DEPRECATED_RFC2818_CLASS
+#else   // BOOST_VERSION >= 107300
     ctx.set_verify_callback(ssl::rfc2818_verification{option.serverName_.value_or(serverName)});
-#endif  // DEPRECATED_RFC2818_CLASS
+#endif  // BOOST_VERSION >= 107300
   }
   return ctx;
 }
@@ -95,16 +96,10 @@ unique_ptr<Ingress> makeShadowsocksIngress(Socket&& s,
   psk = {container,
          crypto::generateKey(option.method_, ConstBuffer<uint8_t>{option.password_}, container)};
   switch (option.method_) {
-#if MBEDTLS_VERSION_MAJOR < 3
   case CryptoMethod::RC4_MD5:
     return make_unique<SSStreamAdapter<CryptoMethod::RC4_MD5, Socket>>(psk, forward<Socket>(s));
   case CryptoMethod::BF_CFB:
     return make_unique<SSStreamAdapter<CryptoMethod::BF_CFB, Socket>>(psk, forward<Socket>(s));
-#else   // MBEDTLS_VERSION_MAJOR < 3
-  case CryptoMethod::RC4_MD5:
-  case CryptoMethod::BF_CFB:
-    fail(PichiError::SEMANTIC_ERROR, vo::msg::DEPRECATED_METHOD);
-#endif  // MBEDTLS_VERSION_MAJOR < 3
   case CryptoMethod::AES_128_CTR:
     return make_unique<SSStreamAdapter<CryptoMethod::AES_128_CTR, Socket>>(psk, forward<Socket>(s));
   case CryptoMethod::AES_192_CTR:
@@ -158,16 +153,10 @@ static unique_ptr<Egress> makeShadowsocksEgress(vo::Sh
   auto psk = MutableBuffer<uint8_t>{container, len};
 
   switch (option.method_) {
-#if MBEDTLS_VERSION_MAJOR < 3
   case CryptoMethod::RC4_MD5:
     return make_unique<SSStreamAdapter<CryptoMethod::RC4_MD5, TCPSocket>>(psk, io);
   case CryptoMethod::BF_CFB:
     return make_unique<SSStreamAdapter<CryptoMethod::BF_CFB, TCPSocket>>(psk, io);
-#else   // MBEDTLS_VERSION_MAJOR < 3
-  case CryptoMethod::RC4_MD5:
-  case CryptoMethod::BF_CFB:
-    fail(PichiError::SEMANTIC_ERROR, vo::msg::DEPRECATED_METHOD);
-#endif  // MBEDTLS_VERSION_MAJOR < 3
   case CryptoMethod::AES_128_CTR:
     return make_unique<SSStreamAdapter<CryptoMethod::AES_128_CTR, TCPSocket>>(psk, io);
   case CryptoMethod::AES_192_CTR:
