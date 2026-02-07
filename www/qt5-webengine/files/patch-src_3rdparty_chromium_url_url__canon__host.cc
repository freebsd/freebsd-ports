--- src/3rdparty/chromium/url/url_canon_host.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/url/url_canon_host.cc
@@ -135,8 +135,7 @@ bool DoSimpleHost(const INCHAR* host,
     if (source == '%') {
       // Unescape first, if possible.
       // Source will be used only if decode operation was successful.
-      if (!DecodeEscaped(host, &i, host_len,
-                         reinterpret_cast<unsigned char*>(&source))) {
+      if (!DecodeEscaped(host, &i, host_len, &source)) {
         // Invalid escaped character. There is nothing that can make this
         // host valid. We append an escaped percent so the URL looks reasonable
         // and mark as failed.
