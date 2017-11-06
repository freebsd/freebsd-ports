--- src/portscan-buildcycle.adb.orig	2017-04-20 10:12:27.241713000 +1200
+++ src/portscan-buildcycle.adb	2017-04-20 10:12:38.218162000 +1200
@@ -570,7 +570,7 @@
       status      : Unix.process_exit;
       lock_lines  : Natural;
       quartersec  : one_minute := one_minute'First;
-      hangmonitor : constant Boolean := True;
+      hangmonitor : constant Boolean := False;
       synthexec   : constant String := host_localbase & "/libexec/synthexec";
       truecommand : constant String := synthexec & " " &
                              log_name (trackers (id).seq_id) & " " & command;
