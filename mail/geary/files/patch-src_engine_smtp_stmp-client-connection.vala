diff --git src/engine/smtp/smtp-client-connection.vala src/engine/smtp/smtp-client-connection.vala
index d62dd42..f629a64 100644
--- src/engine/smtp/smtp-client-connection.vala.orig
+++ src/engine/smtp/smtp-client-connection.vala
@@ -246,8 +246,7 @@ public class Geary.Smtp.ClientConnection {
                 if (!starttls_response.code.is_starttls_ready())
                     throw new SmtpError.STARTTLS_FAILED("STARTTLS failed: %s", response.to_string());
                 
-                TlsClientConnection tls_cx = yield endpoint.starttls_handshake_async(cx,
-                    socket_cx.get_remote_address(), cancellable);
+                TlsClientConnection tls_cx = yield endpoint.starttls_handshake_async(cx, cancellable);
                 cx = tls_cx;
                 set_data_streams(tls_cx);
                 
