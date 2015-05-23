--- amqp_exchange.c.orig	2015-05-07 08:07:00 UTC
+++ amqp_exchange.c
@@ -511,6 +511,8 @@ PHP_METHOD(amqp_exchange_class, declareE
 		amqp_cstring_bytes(exchange->type),
 		exchange->passive,
 		exchange->durable,
+		0, /* auto_delete */
+		0, /* internal */
 		*arguments
 	);
 
