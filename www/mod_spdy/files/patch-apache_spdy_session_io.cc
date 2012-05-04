--- mod_spdy/apache/apache_spdy_session_io.cc.org	2012-03-31 16:28:56.502800000 +0900
+++ mod_spdy/apache/apache_spdy_session_io.cc	2012-03-31 20:46:33.033900102 +0900
@@ -15,6 +15,9 @@
 #include "mod_spdy/apache/apache_spdy_session_io.h"
 
 #include "apr_buckets.h"
+// When HAVE_SYSLOG is defined, apache http_log.h will include syslog.h, which
+// #defined LOG_* as numbers. This conflicts with what we are using those here.
+#undef HAVE_SYSLOG
 #include "http_log.h"
 #include "util_filter.h"
 
