--- src/main/process.c.orig	2024-08-24 13:06:25 UTC
+++ src/main/process.c
@@ -5708,6 +5708,10 @@ static void event_new_fd(rad_listen_t *this)
 			this->status = RAD_LISTEN_STATUS_KNOWN;
 
 #ifdef WITH_TLS
+			if (this->type == RAD_LISTEN_DETAIL) {
+				return;
+			}
+
 			sock = this->data;
 			if (!sock->write_handler) return;
 
