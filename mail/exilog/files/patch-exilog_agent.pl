--- exilog_agent.pl.orig	Sat Jun  4 19:36:03 2005
+++ exilog_agent.pl	Sat Jun  4 19:39:00 2005
@@ -46,7 +46,11 @@
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
