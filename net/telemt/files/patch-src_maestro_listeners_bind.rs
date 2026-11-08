--- src/maestro/listeners/bind.rs.orig	2026-09-28 20:30:20 UTC
+++ src/maestro/listeners/bind.rs
@@ -28,12 +28,15 @@ pub(crate) struct BoundListeners {
 
 /// Owns sockets bound before process accept loops start.
 pub(crate) struct BoundListeners {
+    /// TCP endpoints awaiting accept-loop startup.
     pub(super) listeners: Vec<BoundTcpListener>,
+    /// Optional Unix endpoint awaiting accept-loop startup.
     #[cfg(unix)]
     pub(super) unix_listener: Option<UnixListener>,
 }
 
 impl BoundListeners {
+    /// Reports whether neither TCP nor Unix endpoints were bound.
     pub(crate) fn is_empty(&self) -> bool {
         let tcp_empty = self.listeners.is_empty();
         #[cfg(unix)]
@@ -49,7 +52,9 @@ pub(super) struct BoundTcpListener {
 
 /// Active socket and immutable connection policy for one endpoint.
 pub(super) struct BoundTcpListener {
+    /// Shared listening socket for the endpoint.
     pub(super) listener: Arc<TcpListener>,
+    /// Immutable policy associated with the listening socket.
     pub(super) spec: ListenerBindSpec,
 }
 
@@ -99,6 +104,7 @@ fn log_bind_error(addr: SocketAddr, reuse_allow: bool,
     }
 }
 
+/// Binds a candidate socket without starting to listen.
 pub(super) fn prepare_listener(spec: ListenerBindSpec) -> std::io::Result<PreparedTcpListener> {
     match bind_listener_socket(spec.addr, &spec.options) {
         Ok(socket) => Ok(PreparedTcpListener { socket, spec }),
@@ -110,6 +116,7 @@ impl PreparedTcpListener {
 }
 
 impl PreparedTcpListener {
+    /// Starts listening and transfers the socket to the async runtime.
     pub(super) fn activate(self) -> std::io::Result<BoundTcpListener> {
         activate_listener_socket(&self.socket, self.spec.options.backlog)?;
         let listener = TcpListener::from_std(self.socket.into())?;
@@ -307,7 +314,7 @@ pub(crate) async fn bind_listeners(
                     if let Err(error_value) = fchmodat(
                         anchored_path.parent(),
                         anchored_path.name(),
-                        Mode::from_bits_truncate(mode),
+                        Mode::from_bits_truncate(mode as libc::mode_t),
                         FchmodatFlags::NoFollowSymlink,
                     ) {
                         error!(
