--- mod_spdy/mod_spdy.cc.org	2012-03-31 16:28:56.745777000 +0900
+++ mod_spdy/mod_spdy.cc	2012-03-31 20:48:01.337782696 +0900
@@ -22,6 +22,9 @@
 #include "httpd.h"
 #include "http_connection.h"
 #include "http_config.h"
+// When HAVE_SYSLOG is defined, apache http_log.h will include syslog.h, which
+// #defined LOG_* as numbers. This conflicts with what we are using those here.
+#undef HAVE_SYSLOG
 #include "http_log.h"
 #include "http_protocol.h"
 #include "http_request.h"
