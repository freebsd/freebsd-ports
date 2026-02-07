--- src/amqp_plugin.h.orig	2022-12-31 20:17:17.000000000 +0100
+++ src/amqp_plugin.h	2024-03-29 19:09:18.874002000 +0100
@@ -22,8 +22,8 @@
 #define AMQP_PLUGIN_COMMON_H
 
 /* includes */
-#include <amqp.h>
-#include <amqp_tcp_socket.h>
+#include <rabbitmq-c/amqp.h>
+#include <rabbitmq-c/tcp_socket.h>
 #include <sys/poll.h>
 
 #include "plugin_common.h"
