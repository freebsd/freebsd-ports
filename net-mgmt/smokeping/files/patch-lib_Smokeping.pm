--- lib/Smokeping.pm.orig	2021-11-14 17:05:16 UTC
+++ lib/Smokeping.pm
@@ -4631,7 +4631,7 @@
         if(defined $opt{'check'}) { verify_cfg($cfgfile); exit 0; }
         if($opt{reload})  { 
             load_cfg $cfgfile, 'noinit'; # we need just the piddir
-            kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGHUP; 
+            kill_smoke $cfg->{General}{piddir}."/pid", SIGHUP; 
             print "HUP signal sent to the running SmokePing process, exiting.\n";
             exit 0;
         };
@@ -4640,7 +4640,7 @@
         if(defined $opt{'static-pages'}) { makestaticpages $cfg, $opt{'static-pages'}; exit 0 };
         if($opt{email})    { enable_dynamic $cfg, $cfg->{Targets},"",""; exit 0 };
     }
-    if($opt{restart})  { kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGINT;};
+    if($opt{restart})  { kill_smoke $cfg->{General}{piddir}."/pid", SIGINT;};
 
     if($opt{logfile})      { initialize_filelog($opt{logfile}) };
 
@@ -4653,7 +4653,7 @@
                 initialize_syslog($cfg->{General}{syslogfacility}, 
                                   $cfg->{General}{syslogpriority});
         }
-        daemonize_me $cfg->{General}{piddir}."/smokeping.pid";
+        daemonize_me $cfg->{General}{piddir}."/pid";
     }
     do_log "Smokeping version $VERSION successfully launched.";
 
@@ -4839,7 +4839,7 @@
             my $new_conf = Smokeping::Slave::submit_results $slave_cfg,$cfg,$myprobe,$probes;
             if ($new_conf && !$gothup){
                 do_log('server has new config for me ... HUPing the parent');
-                kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGHUP; 
+                kill_smoke $cfg->{General}{piddir}."/pid", SIGHUP; 
                 # wait until the parent signals back if it didn't already
                 sleep if (!$gothup);
                 if (!$gothup) {
