--- src/3rdparty/chromium/net/http/http_network_session.cc.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/http/http_network_session.cc
@@ -17,7 +17,9 @@
 #include "base/strings/string_util.h"
 #include "base/values.h"
 #include "net/base/network_throttle_manager.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory_impl.h"
 #include "net/http/url_security_manager.h"
