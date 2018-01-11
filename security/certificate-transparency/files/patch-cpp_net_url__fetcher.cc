--- cpp/net/url_fetcher.cc.orig	2018-01-04 08:54:28 UTC
+++ cpp/net/url_fetcher.cc
@@ -4,7 +4,7 @@
 #include <event2/keyvalq_struct.h>
 #include <evhtp.h>
 #include <glog/logging.h>
-#include <htparse.h>
+#include <parser.h>
 
 #include "net/connection_pool.h"
 #include "util/thread_pool.h"
