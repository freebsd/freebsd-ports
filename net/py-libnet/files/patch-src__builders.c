--- ./src/builders.c.orig	2014-05-30 12:55:10.000000000 +0200
+++ ./src/builders.c	2014-05-30 13:00:15.000000000 +0200
@@ -722,9 +722,9 @@
 	u_int16_t sum = 0;
 	u_int16_t id = PYLIBNET_RANDOM_U16;
 	u_int16_t seq = PYLIBNET_RANDOM_U16;
-	n_time otime = PYLIBNET_RANDOM_U32;
-	n_time rtime = PYLIBNET_RANDOM_U32;
-	n_time ttime = PYLIBNET_RANDOM_U32;
+	u_int32_t otime = PYLIBNET_RANDOM_U32;
+	u_int32_t rtime = PYLIBNET_RANDOM_U32;
+	u_int32_t ttime = PYLIBNET_RANDOM_U32;
 	u_int8_t *payload = NULL;
 	u_int32_t payload_s = 0;
 	libnet_ptag_t ptag = 0;
