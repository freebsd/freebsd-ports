--- plexWatch.pl.orig	2016-03-26 19:12:31 UTC
+++ plexWatch.pl
@@ -42,15 +42,14 @@ if ($^O ne 'MSWin32') {
 ## end
 
 ## load config file
-my $dirname = dirname(__FILE__);
-if (!-e $dirname .'/config.pl') {
-    my $msg = "** missing file $dirname/config.pl. Did you move edit config.pl-dist and copy to config.pl?";
+if (!-e '%%ETCDIR%%/config.pl') {
+    my $msg = "** missing file %%ETCDIR%%/config.pl. Did you move edit config.pl-dist and copy to config.pl?";
     &DebugLog($msg,1) if $msg;
     exit;
 }
 our ($data_dir, $server, $port, $appname, $user_display, $alert_format, $notify, $push_titles, $backup_opts, $myPlex_user, $myPlex_pass, $server_log, $log_client_ip, $debug_logging, $watched_show_completed, $watched_grouping_maxhr, $count_paused, $inc_non_library_content, @exclude_library_ids);
 my @config_vars = ("data_dir", "server", "port", "appname", "user_display", "alert_format", "notify", "push_titles", "backup_opts", "myPlex_user", "myPlex_pass", "server_log", "log_client_ip", "debug_logging", "watched_show_completed", "watched_grouping_maxhr", "count_paused", "exclude_library_ids");
-do $dirname.'/config.pl';
+do '%%ETCDIR%%/config.pl';
 
 if (!$data_dir || !$server || !$port || !$appname || !$alert_format || !$notify) {
     ## TODO - make this information a little more useful!
