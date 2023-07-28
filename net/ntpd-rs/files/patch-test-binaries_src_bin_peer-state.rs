--- test-binaries/src/bin/peer-state.rs.orig	2023-07-28 10:30:19 UTC
+++ test-binaries/src/bin/peer-state.rs
@@ -3,7 +3,7 @@ async fn main() -> Result<(), Box<dyn Error>> {
 
 #[tokio::main]
 async fn main() -> Result<(), Box<dyn Error>> {
-    let mut stream = tokio::net::UnixStream::connect("/run/ntpd-rs/observe").await?;
+    let mut stream = tokio::net::UnixStream::connect("/var/run/ntpd-rs/observe").await?;
 
     let mut msg = Vec::with_capacity(16 * 1024);
     let output: ObservableState = ntp_daemon::sockets::read_json(&mut stream, &mut msg).await?;
