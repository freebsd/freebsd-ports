--- src/3rdparty/chromium/net/http/http_network_session.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/http/http_network_session.cc
@@ -20,7 +20,9 @@
 #include "build/build_config.h"
 #include "net/base/features.h"
 #include "net/dns/host_resolver.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory.h"
 #include "net/http/url_security_manager.h"
