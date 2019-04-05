--- net/http/http_network_session.cc.orig	2019-03-11 22:01:01 UTC
+++ net/http/http_network_session.cc
@@ -19,7 +19,9 @@
 #include "base/trace_event/memory_dump_request_args.h"
 #include "base/trace_event/process_memory_dump.h"
 #include "base/values.h"
+#if defined(USE_KERBEROS)
 #include "net/http/http_auth_handler_factory.h"
+#endif
 #include "net/http/http_response_body_drainer.h"
 #include "net/http/http_stream_factory.h"
 #include "net/http/url_security_manager.h"
