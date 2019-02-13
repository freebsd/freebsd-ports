--- lib/Smokeping.pm.orig	2018-02-02 21:14:55 UTC
+++ lib/Smokeping.pm
@@ -4306,7 +4306,7 @@ sub main (;$) {
         if(defined $opt{'check'}) { verify_cfg($cfgfile); exit 0; }
         if($opt{reload})  { 
             load_cfg $cfgfile, 'noinit'; # we need just the piddir
-            kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGHUP; 
+            kill_smoke $cfg->{General}{piddir}."/pid", SIGHUP; 
             print "HUP signal sent to the running SmokePing process, exiting.\n";
             exit 0;
         };
@@ -4315,7 +4315,7 @@ sub main (;$) {
         if(defined $opt{'static-pages'}) { makestaticpages $cfg, $opt{'static-pages'}; exit 0 };
         if($opt{email})    { enable_dynamic $cfg, $cfg->{Targets},"",""; exit 0 };
     }
-    if($opt{restart})  { kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGINT;};
+    if($opt{restart})  { kill_smoke $cfg->{General}{piddir}."/pid", SIGINT;};
 
     if($opt{logfile})      { initialize_filelog($opt{logfile}) };
 
@@ -4328,7 +4328,7 @@ sub main (;$) {
                 initialize_syslog($cfg->{General}{syslogfacility}, 
                                   $cfg->{General}{syslogpriority});
         }
-        daemonize_me $cfg->{General}{piddir}."/smokeping.pid";
+        daemonize_me $cfg->{General}{piddir}."/pid";
     }
     do_log "Smokeping version $VERSION successfully launched.";
 
@@ -4514,7 +4514,7 @@ KID:
             my $new_conf = Smokeping::Slave::submit_results $slave_cfg,$cfg,$myprobe,$probes;
             if ($new_conf && !$gothup){
                 do_log('server has new config for me ... HUPing the parent');
-                kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGHUP; 
+                kill_smoke $cfg->{General}{piddir}."/pid", SIGHUP; 
                 # wait until the parent signals back if it didn't already
                 sleep if (!$gothup);
                 if (!$gothup) {
