--- mod_spdy/mod_spdy.cc.orig	2012-05-14 20:42:33.000000000 +0900
+++ mod_spdy/mod_spdy.cc	2012-05-17 23:33:20.000000000 +0900
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
@@ -790,7 +793,7 @@
 
   // Declare our module object (note that "module" is a typedef for "struct
   // module_struct"; see http_config.h for the definition of module_struct).
-  module AP_MODULE_DECLARE_DATA spdy_module = {
+  struct module_struct __attribute__((visibility("default")))  spdy_module = {
     // This next macro indicates that this is a (non-MPM) Apache 2.0 module
     // (the macro actually expands to multiple comma-separated arguments; see
     // http_config.h for the definition):
