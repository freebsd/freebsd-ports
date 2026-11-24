--- zellij-client/src/lib.rs.orig	2026-11-24 06:52:44 UTC
+++ zellij-client/src/lib.rs
@@ -964,7 +964,7 @@ pub fn start_remote_client(
     )?;
 
     let reconnect_to_session = None;
-    os_input.unset_raw_mode().unwrap();
+    let _ = os_input.unset_raw_mode();
 
     let mut stdout = os_input.get_stdout_writer();
     stdout.write_all(ENTER_ALTERNATE_SCREEN.as_bytes()).unwrap();
@@ -1023,8 +1023,8 @@ pub fn start_remote_client(
         os_input.restore_console_mode();
         let error = terminal_teardown_message(&e, full_screen_ws.rows, false, false);
         let mut stdout = os_input.get_stdout_writer();
-        stdout.write_all(error.as_bytes()).unwrap();
-        stdout.flush().unwrap();
+        let _ = stdout.write_all(error.as_bytes());
+        let _ = stdout.flush();
         if exit_status == 0 {
             log::info!("{}", e);
         } else {
@@ -1232,7 +1232,7 @@ pub fn start_client(
         .unwrap_or(true);
     let should_start_web_server = config_options.web_server.map(|w| w).unwrap_or(false);
     let mut reconnect_to_session = None;
-    os_input.unset_raw_mode().unwrap();
+    let _ = os_input.unset_raw_mode();
 
     if !is_a_reconnect {
         // we don't do this for a reconnect because our controlling terminal already has the
