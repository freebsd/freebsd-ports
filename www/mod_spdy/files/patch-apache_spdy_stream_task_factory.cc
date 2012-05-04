--- mod_spdy/apache/apache_spdy_stream_task_factory.cc.org	2012-03-31 16:28:56.491796000 +0900
+++ mod_spdy/apache/apache_spdy_stream_task_factory.cc	2012-03-31 20:46:51.134788973 +0900
@@ -25,6 +25,9 @@
 
 #include "apr_buckets.h"
 #include "apr_network_io.h"
+// When HAVE_SYSLOG is defined, apache http_log.h will include syslog.h, which
+// #defined LOG_* as numbers. This conflicts with what we are using those here.
+#undef HAVE_SYSLOG
 #include "http_log.h"
 #include "util_filter.h"
 
