--- net/http/http_network_session.cc.orig	2018-06-13 00:10:22.000000000 +0200
+++ net/http/http_network_session.cc	2018-07-19 15:24:13.890886000 +0200
@@ -20,7 +20,9 @@
 #include "base/trace_event/memory_dump_request_args.h"
 #include "base/trace_event/process_memory_dump.h"
 #include "base/values.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory_impl.h"
 #include "net/http/url_security_manager.h"
