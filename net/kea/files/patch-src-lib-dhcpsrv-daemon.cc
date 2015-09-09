--- src/lib/dhcpsrv/daemon.cc.orig	2015-07-23 16:45:11 UTC
+++ src/lib/dhcpsrv/daemon.cc
@@ -36,7 +36,7 @@ namespace dhcp {
 
 Daemon::Daemon()
     : signal_set_(), signal_handler_(), config_file_(""), proc_name_(""),
-    pid_file_dir_(DHCP_DATA_DIR), pid_file_(), am_file_author_(false) {
+    pid_file_dir_(KEA_PIDFILE_DIR), pid_file_(), am_file_author_(false) {
 
     // The pid_file_dir can be overridden via environment variable
     // This is primarily intended to simplify testing
