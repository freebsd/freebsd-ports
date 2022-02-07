--- src/server.rs.orig	2021-01-12 22:25:51 UTC
+++ src/server.rs
@@ -63,6 +63,7 @@ use tokio_io::{AsyncRead, AsyncWrite};
 use tokio_serde_bincode::{ReadBincode, WriteBincode};
 use tokio_tcp::TcpListener;
 use tokio_timer::{Delay, Timeout};
+use tokio_uds::UnixListener;
 use tower::Service;
 
 use crate::errors::*;
@@ -430,8 +431,9 @@ pub fn start_server(config: &Config, port: u16) -> Res
 }
 
 pub struct SccacheServer<C: CommandCreatorSync> {
+    unix_socket_path: String,
     runtime: Runtime,
-    listener: TcpListener,
+    listener: UnixListener,
     rx: mpsc::Receiver<ServerMessage>,
     timeout: Duration,
     service: SccacheService<C>,
@@ -447,8 +449,8 @@ impl<C: CommandCreatorSync> SccacheServer<C> {
         dist_client: DistClientContainer,
         storage: Arc<dyn Storage>,
     ) -> Result<SccacheServer<C>> {
-        let addr = SocketAddrV4::new(Ipv4Addr::new(127, 0, 0, 1), port);
-        let listener = TcpListener::bind(&SocketAddr::V4(addr))?;
+        let unix_socket_path = env::var("SCCACHE_UNIX_LISTEN")?;
+        let listener = UnixListener::bind(&unix_socket_path)?;
 
         // Prepare the service which we'll use to service all incoming TCP
         // connections.
@@ -457,6 +459,7 @@ impl<C: CommandCreatorSync> SccacheServer<C> {
         let service = SccacheService::new(dist_client, storage, &client, pool, tx, info);
 
         Ok(SccacheServer {
+            unix_socket_path,
             runtime,
             listener,
             rx,
@@ -493,7 +496,7 @@ impl<C: CommandCreatorSync> SccacheServer<C> {
     /// Returns the port that this server is bound to
     #[allow(dead_code)]
     pub fn port(&self) -> u16 {
-        self.listener.local_addr().unwrap().port()
+        0
     }
 
     /// Runs this server to completion.
@@ -510,6 +513,7 @@ impl<C: CommandCreatorSync> SccacheServer<C> {
 
     fn _run<'a>(self, shutdown: Box<dyn Future<Item = (), Error = ()> + 'a>) -> io::Result<()> {
         let SccacheServer {
+            unix_socket_path,
             mut runtime,
             listener,
             rx,
@@ -593,6 +597,8 @@ impl<C: CommandCreatorSync> SccacheServer<C> {
                     io::Error::new(io::ErrorKind::Other, e)
                 }
             })?;
+
+        std::fs::remove_file(unix_socket_path);
 
         info!("ok, fully shutting down now");
 
