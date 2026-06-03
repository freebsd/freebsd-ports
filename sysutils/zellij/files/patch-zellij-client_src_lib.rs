--- zellij-client/src/lib.rs.orig	2026-05-13 07:48:47 UTC
+++ zellij-client/src/lib.rs
@@ -683,12 +683,12 @@ pub fn start_remote_client(
 
     let reset_controlling_terminal_state = |e: String, exit_status: i32| {
         os_input.disable_mouse().non_fatal();
-        os_input.unset_raw_mode().unwrap();
+        let _ = os_input.unset_raw_mode();
         os_input.restore_console_mode();
         let error = terminal_teardown_message(&e, full_screen_ws.rows, true);
         let mut stdout = os_input.get_stdout_writer();
-        stdout.write_all(error.as_bytes()).unwrap();
-        stdout.flush().unwrap();
+        let _ = stdout.write_all(error.as_bytes());
+        let _ = stdout.flush();
         if exit_status == 0 {
             log::info!("{}", e);
         } else {
@@ -1264,16 +1264,16 @@ pub fn start_client(
 
         os_input.disable_mouse().non_fatal();
         info!("{}", exit_msg);
-        os_input.unset_raw_mode().unwrap();
+        let _ = os_input.unset_raw_mode();
         os_input.restore_console_mode();
         let mut stdout = os_input.get_stdout_writer();
-        stdout.write_all(goodbye_message.as_bytes()).unwrap();
-        stdout.flush().unwrap();
+        let _ = stdout.write_all(goodbye_message.as_bytes());
+        let _ = stdout.flush();
     } else {
         let clear_screen = "\u{1b}[2J";
         let mut stdout = os_input.get_stdout_writer();
-        stdout.write_all(clear_screen.as_bytes()).unwrap();
-        stdout.flush().unwrap();
+        let _ = stdout.write_all(clear_screen.as_bytes());
+        let _ = stdout.flush();
     }
 
     let _ = send_input_instructions.send(InputInstruction::Exit);
