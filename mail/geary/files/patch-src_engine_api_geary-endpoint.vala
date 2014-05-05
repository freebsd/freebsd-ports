diff --git src/engine/api/geary-endpoint.vala src/engine/api/geary-endpoint.vala
index d933644..bf0ab51 100644
--- src/engine/api/geary-endpoint.vala.orig
+++ src/engine/api/geary-endpoint.vala
@@ -32,8 +32,7 @@ public class Geary.Endpoint : BaseObject {
         HALT
     }
     
-    public string host_specifier { get; private set; }
-    public uint16 default_port { get; private set; }
+    public NetworkAddress remote_address { get; private set; }
     public Flags flags { get; private set; }
     public uint timeout_sec { get; private set; }
     public TlsCertificateFlags tls_validation_flags { get; set; default = TlsCertificateFlags.VALIDATE_ALL; }
@@ -50,8 +49,7 @@ public class Geary.Endpoint : BaseObject {
     private SocketClient? socket_client = null;
     
     public Endpoint(string host_specifier, uint16 default_port, Flags flags, uint timeout_sec) {
-        this.host_specifier = host_specifier;
-        this.default_port = default_port;
+        this.remote_address = new NetworkAddress(host_specifier, default_port);
         this.flags = flags;
         this.timeout_sec = timeout_sec;
     }
@@ -74,8 +72,7 @@ public class Geary.Endpoint : BaseObject {
     }
 
     public async SocketConnection connect_async(Cancellable? cancellable = null) throws Error {
-        SocketConnection cx = yield get_socket_client().connect_to_host_async(host_specifier, default_port,
-            cancellable);
+        SocketConnection cx = yield get_socket_client().connect_async(remote_address, cancellable);
 
         TcpConnection? tcp = cx as TcpConnection;
         if (tcp != null)
@@ -85,8 +82,8 @@ public class Geary.Endpoint : BaseObject {
     }
     
     public async TlsClientConnection starttls_handshake_async(IOStream base_stream,
-        SocketConnectable connectable, Cancellable? cancellable = null) throws Error {
-        TlsClientConnection tls_cx = TlsClientConnection.new(base_stream, connectable);
+        Cancellable? cancellable = null) throws Error {
+        TlsClientConnection tls_cx = TlsClientConnection.new(base_stream, remote_address);
         prepare_tls_cx(tls_cx, true);
         
         yield tls_cx.handshake_async(Priority.DEFAULT, cancellable);
@@ -196,7 +193,7 @@ public class Geary.Endpoint : BaseObject {
     }
     
     public string to_string() {
-        return "%s/default:%u".printf(host_specifier, default_port);
+        return "%s/default:%u".printf(remote_address.hostname, remote_address.port);
     }
 }
