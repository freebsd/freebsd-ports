--- src/common/kernel-consumer/kernel-consumer.h.orig	2016-11-29 22:48:37 UTC
+++ src/common/kernel-consumer/kernel-consumer.h
@@ -19,6 +19,8 @@
 #ifndef _LTTNG_KCONSUMER_H
 #define _LTTNG_KCONSUMER_H
 
+#include <errno.h>
+
 #include <common/consumer/consumer.h>
 
 int lttng_kconsumer_take_snapshot(struct lttng_consumer_stream *stream);
