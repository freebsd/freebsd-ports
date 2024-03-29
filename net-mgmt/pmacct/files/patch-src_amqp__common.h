--- src/amqp_common.h.orig	2022-12-31 20:17:17.000000000 +0100
+++ src/amqp_common.h	2024-03-29 19:10:46.740680000 +0100
@@ -23,8 +23,9 @@
 #define AMQP_COMMON_H
 
 /* includes */
-#include <amqp.h>
-#include <amqp_tcp_socket.h>
+#include <rabbitmq-c/amqp.h>
+#include <rabbitmq-c/tcp_socket.h>
+#include <rabbitmq-c/ssl_socket.h>
 #include "plugin_common.h"
 
 /* defines */
