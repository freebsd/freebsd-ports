--- src/platform/mod.rs.orig	2026-09-29 14:11:39 UTC
+++ src/platform/mod.rs
@@ -158,7 +158,7 @@ pub(crate) fn prepare_server_process(_handoff_import: 
     Ok(false)
 }
 
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
 pub fn detach_server_daemon_command(command: &mut std::process::Command) {
     use std::os::unix::process::CommandExt;
 
@@ -175,7 +175,7 @@ pub fn detach_server_daemon_command(command: &mut std:
     }
 }
 
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
 pub fn current_process_is_detached_server_daemon() -> bool {
     unsafe { libc::getsid(0) == libc::getpid() }
 }
@@ -284,7 +284,7 @@ pub(crate) const REMOTE_BRIDGE_IDLE_TIMEOUT_SUPPORTED:
 }
 
 pub(crate) const REMOTE_BRIDGE_IDLE_TIMEOUT_SUPPORTED: bool =
-    cfg!(any(target_os = "linux", target_os = "macos"));
+    cfg!(any(target_os = "linux", target_os = "macos", target_os = "freebsd"));
 
 #[cfg(unix)]
 mod remote_bridge;
@@ -311,6 +311,11 @@ pub use linux::*;
 #[cfg(target_os = "linux")]
 pub use linux::*;
 
+#[cfg(target_os = "freebsd")]
+mod freebsd;
+#[cfg(target_os = "freebsd")]
+pub use freebsd::*;
+
 #[cfg(target_os = "macos")]
 mod macos;
 #[cfg(target_os = "macos")]
@@ -321,12 +326,22 @@ pub use windows::*;
 #[cfg(target_os = "windows")]
 pub use windows::*;
 
-#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+#[cfg(not(any(
+    target_os = "linux",
+    target_os = "macos",
+    target_os = "windows",
+    target_os = "freebsd"
+)))]
 mod fallback;
-#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+#[cfg(not(any(
+    target_os = "linux",
+    target_os = "macos",
+    target_os = "windows",
+    target_os = "freebsd"
+)))]
 pub use fallback::*;
 
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
 pub(crate) fn available_pane_shell_from_job(child_pid: u32, job: ForegroundJob) -> Option<String> {
     if job.process_group_id != child_pid
         || job.processes.iter().any(|process| process.pid != child_pid)
@@ -349,7 +364,7 @@ fn normalized_process_name(name: &str) -> String {
         .to_ascii_lowercase()
 }
 
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
 pub(crate) fn is_powershell_process_name(name: &str) -> bool {
     matches!(
         normalized_process_name(name).as_str(),
@@ -357,7 +372,7 @@ pub(crate) fn is_powershell_process_name(name: &str) -
     )
 }
 
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
 pub(crate) fn interactive_unix_shell_command(
     argv: &[String],
     shell_name: &str,
@@ -440,12 +455,12 @@ pub(crate) fn is_pane_shell_process_name(name: &str) -
     )
 }
 
-#[cfg(not(any(target_os = "linux", target_os = "macos")))]
+#[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "freebsd")))]
 pub fn process_agent_hint(_pid: u32) -> Option<crate::detect::Agent> {
     None
 }
 
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
 pub(crate) fn parse_agent_env_hint(environ: &[u8]) -> Option<crate::detect::Agent> {
     for record in environ.split(|&byte| byte == 0) {
         let Some(value) = record.strip_prefix(b"HERDR_AGENT=") else {
@@ -574,7 +589,7 @@ mod tests {
         );
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
     #[test]
     fn parse_agent_env_hint_accepts_known_agents() {
         assert_eq!(
@@ -587,14 +602,14 @@ mod tests {
         );
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
     #[test]
     fn parse_agent_env_hint_ignores_missing_or_unknown_agents() {
         assert_eq!(parse_agent_env_hint(b"PATH=/bin\0TERM=xterm\0"), None);
         assert_eq!(parse_agent_env_hint(b"HERDR_AGENT=not-an-agent\0"), None);
     }
 
-    #[cfg(any(target_os = "linux", target_os = "macos"))]
+    #[cfg(any(target_os = "linux", target_os = "macos", target_os = "freebsd"))]
     #[test]
     fn interactive_shell_command_quotes_for_posix_and_powershell() {
         let argv = vec![
