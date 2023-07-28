--- ntp-ctl/src/lib.rs.orig	2023-07-28 10:29:56 UTC
+++ ntp-ctl/src/lib.rs
@@ -95,12 +95,12 @@ pub async fn main() -> std::io::Result<ExitCode> {
     let observation = cli
         .observation_socket
         .or(config.observe.path)
-        .unwrap_or_else(|| PathBuf::from("/run/ntpd-rs/observe"));
+        .unwrap_or_else(|| PathBuf::from("/var/run/ntpd-rs/observe"));
 
     let configuration = cli
         .configuration_socket
         .or(config.configure.path)
-        .unwrap_or_else(|| PathBuf::from("/run/ntpd-rs/configure"));
+        .unwrap_or_else(|| PathBuf::from("/var/run/ntpd-rs/configure"));
 
     match cli.command {
         Command::Peers => print_state(PrintState::Peers, observation).await,
