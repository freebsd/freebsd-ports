--- lib/Smokeping.pm.orig	2015-02-12 19:31:21.000000000 +0100
+++ lib/Smokeping.pm	2015-02-12 19:34:23.000000000 +0100
@@ -2632,12 +2632,14 @@
         {
          %$DIRCHECK_SUB,
          _doc => <<DOC,
-The base directory where SmokePing keeps the files related to the DYNAMIC function.
-This directory must be writeable by the WWW server. It is also used for temporary
-storage of slave polling results by the master in 
+The base directory where SmokePing keeps the files related to the DYNAMIC
+function.
+This directory must be writeable by the WWW server. It is also used for
+temporary storage of slave polling results by the master in 
 L<the masterE<sol>slave mode|smokeping_master_slave>.
 
-If this variable is not specified, the value of C<datadir> will be used instead.
+If this variable is not specified, the value of C<datadir> will be
+used instead.
 DOC
         },
         piddir  =>
@@ -4214,7 +4216,7 @@
         if(defined $opt{'check'}) { verify_cfg($cfgfile); exit 0; }
         if($opt{reload})  { 
             load_cfg $cfgfile, 'noinit'; # we need just the piddir
-            kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGHUP; 
+            kill_smoke $cfg->{General}{piddir}."/pid", SIGHUP; 
             print "HUP signal sent to the running SmokePing process, exiting.\n";
             exit 0;
         };
@@ -4223,7 +4225,7 @@
         if(defined $opt{'static-pages'}) { makestaticpages $cfg, $opt{'static-pages'}; exit 0 };
         if($opt{email})    { enable_dynamic $cfg, $cfg->{Targets},"",""; exit 0 };
     }
-    if($opt{restart})  { kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGINT;};
+    if($opt{restart})  { kill_smoke $cfg->{General}{piddir}."/pid", SIGINT;};
 
     if($opt{logfile})      { initialize_filelog($opt{logfile}) };
 
@@ -4236,7 +4238,7 @@
                 initialize_syslog($cfg->{General}{syslogfacility}, 
                                   $cfg->{General}{syslogpriority});
         }
-        daemonize_me $cfg->{General}{piddir}."/smokeping.pid";
+        daemonize_me $cfg->{General}{piddir}."/pid";
     }
     do_log "Smokeping version $VERSION successfully launched.";
 
@@ -4413,7 +4415,7 @@
             my $new_conf = Smokeping::Slave::submit_results $slave_cfg,$cfg,$myprobe,$probes;
             if ($new_conf && !$gothup){
                 do_log('server has new config for me ... HUPing the parent');
-                kill_smoke $cfg->{General}{piddir}."/smokeping.pid", SIGHUP; 
+                kill_smoke $cfg->{General}{piddir}."/pid", SIGHUP; 
                 # wait until the parent signals back if it didn't already
                 sleep if (!$gothup);
                 if (!$gothup) {
