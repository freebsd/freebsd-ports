--- lib/Monitor.pm.orig	2004/02/19 15:58:07	1.31
+++ lib/Monitor.pm	2007/01/21 04:17:22	1.32
@@ -526,14 +526,15 @@
 sub alarmExec {
     my ($args, $action) = @_;
     my $alarmArgs       = $$args[7];
-    system($alarmArgs->[0]);
 
     if ($action eq 'ADD') {
+        system($alarmArgs->[0]);
         Info("Monitor: Triggered event with system command '".
              $alarmArgs->[0]."' .");
     }
 
     else {
+        system($alarmArgs->[1]);
         Info("Monitor: Cleared event with shell command '".
              $alarmArgs->[1]."' .");
     }
