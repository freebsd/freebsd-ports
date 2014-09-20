--- mod_amazon_proxy.c.orig	2010-09-13 22:34:13.000000000 +0900
+++ mod_amazon_proxy.c	2014-09-20 20:09:28.000000000 +0900
@@ -25,7 +25,9 @@
 #include "http_protocol.h"
 #include "http_log.h"
 #include "ap_config.h"
+#include "apr_base64.h"
 #include <apreq2/apreq_param.h>
+#include <apreq2/apreq_util.h>
 
 typedef struct {
     const char *access_key;
