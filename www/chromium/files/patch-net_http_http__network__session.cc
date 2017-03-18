--- net/http/http_network_session.cc.orig	2017-03-09 20:04:35 UTC
+++ net/http/http_network_session.cc
@@ -20,7 +20,9 @@
 #include "base/trace_event/process_memory_dump.h"
 #include "base/values.h"
 #include "net/base/network_throttle_manager_impl.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory_impl.h"
 #include "net/http/url_security_manager.h"
