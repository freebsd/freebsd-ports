--- exilog_agent.pl.orig	2024-04-04 09:07:54 UTC
+++ exilog_agent.pl
@@ -48,7 +48,11 @@ unless ($foreground) {
   };
 
   setsid();
-
+  my $me = "exilog";
+  my $pidfile = "/var/run/".$me.".pid";
+  open (PID,">$pidfile");
+  print PID $$;
+  close (PID); 
   # dup STDOUT/ERR
   open(STDOUT, ">&LOG");
   open(STDERR, ">&LOG");
@@ -413,13 +417,13 @@ sub _tail {
       print STDERR "($$) [exilog_agent:_tail] ($logfile) ".scalar localtime()." ".$_[0];
     };
 
-  # open the file
-  open(LOGFILE,"< $logfile");
-
   # import parser, open DB connection
   use exilog_parse;
   use exilog_sql;
   reconnect();
+
+  # open the file
+  open(LOGFILE,"< $logfile");
 
   my $curpos;
   my $fsize = (-s $logfile);
