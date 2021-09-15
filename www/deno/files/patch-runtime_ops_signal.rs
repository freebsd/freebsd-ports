--- runtime/ops/signal.rs.orig	2021-09-15 11:07:08 UTC
+++ runtime/ops/signal.rs
@@ -57,6 +57,44 @@ impl Resource for SignalStreamResource {
   }
 }
 
+#[cfg(target_os = "freebsd")]
+pub fn signal_str_to_int(s: &str) -> Result<libc::c_int, AnyError> {
+  match s {
+    "SIGHUP" => Ok(1),
+    "SIGINT" => Ok(2),
+    "SIGQUIT" => Ok(3),
+    "SIGILL" => Ok(4),
+    "SIGTRAP" => Ok(5),
+    "SIGABRT" => Ok(6),
+    "SIGEMT" => Ok(7),
+    "SIGFPE" => Ok(8),
+    "SIGKILL" => Ok(9),
+    "SIGBUS" => Ok(10),
+    "SIGSEGV" => Ok(11),
+    "SIGSYS" => Ok(12),
+    "SIGPIPE" => Ok(13),
+    "SIGALRM" => Ok(14),
+    "SIGTERM" => Ok(15),
+    "SIGURG" => Ok(16),
+    "SIGSTOP" => Ok(17),
+    "SIGTSTP" => Ok(18),
+    "SIGCONT" => Ok(19),
+    "SIGCHLD" => Ok(20),
+    "SIGTTIN" => Ok(21),
+    "SIGTTOU" => Ok(22),
+    "SIGIO" => Ok(23),
+    "SIGXCPU" => Ok(24),
+    "SIGXFSZ" => Ok(25),
+    "SIGVTALRM" => Ok(26),
+    "SIGPROF" => Ok(27),
+    "SIGWINCH" => Ok(28),
+    "SIGINFO" => Ok(29),
+    "SIGUSR1" => Ok(30),
+    "SIGUSR2" => Ok(31),
+    _ => Err(type_error(format!("Invalid signal : {}", s))),
+  }
+}
+
 #[cfg(target_os = "linux")]
 pub fn signal_str_to_int(s: &str) -> Result<libc::c_int, AnyError> {
   match s {
