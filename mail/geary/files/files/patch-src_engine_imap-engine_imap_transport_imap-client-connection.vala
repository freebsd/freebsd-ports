diff --git src/engine/imap/transport/imap-client-connection.vala src/engine/imap/transport/imap-client-connection.vala
index 9ca950f..e6dfce7 100644
--- src/engine/imap/transport/imap-client-connection.vala.orig
+++ src/engine/imap/transport/imap-client-connection.vala
@@ -490,8 +490,7 @@ public class Geary.Imap.ClientConnection : BaseObject {
         yield close_channels_async(cancellable);
         
         // wrap connection with TLS connection
-        TlsClientConnection tls_cx = yield endpoint.starttls_handshake_async(cx,
-            cx.get_remote_address(), cancellable);
+        TlsClientConnection tls_cx = yield endpoint.starttls_handshake_async(cx, cancellable);
         
         ios = tls_cx;
         

