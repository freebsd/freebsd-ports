--- subsystem/alertEngine/alertdaemon.pl.orig	Fri Sep  9 10:52:00 2005
+++ subsystem/alertEngine/alertdaemon.pl	Mon Aug 21 10:16:23 2006
@@ -37,9 +37,16 @@
 use IO::Handle;
 
 use NAV::AlertEngine::Engine;
+use vars qw ($pscmd);
 
 #BEGIN {require "alertengine.cfg";}
 
+if ((POSIX::uname)[0] eq "FreeBSD") {
+	$pscmd = "ps axc -opid,tty,time,command";
+} else {
+	$pscmd = "ps -e";
+}
+
 ####################################################
 ## Engine 
 ####################################################
@@ -66,7 +73,7 @@
 		die "Cannot open pidfile";
 	    my ($pid, $tid) = split / /, <pid_file>;
 	    close(pid_file);
-	    open ps_file, "ps -e | grep $pid | wc -l|";
+	    open ps_file, "$pscmd | grep $pid | wc -l|";
 	    my $count=<ps_file>;
 	    close(ps_file);
 	    if($count==0) {
@@ -145,7 +152,7 @@
 			die "Cannot open pidfile";
 		my ($pid, $tid) = split / /, <pid_file>;
 		close(pid_file);
-		open ps_file, "ps -e | grep $pid | wc -l|";
+		open ps_file, "$pscmd | grep $pid | wc -l|";
 		my $count=<ps_file>;
 		close(ps_file);
 		if($count==0) {
@@ -180,7 +187,7 @@
 	    die "Cannot open pidfile";
 	my ($pid, $tid) = split / /, <pid_file>;
 	close(pid_file);
-	open ps_file, "ps -e | grep $pid | wc -l|";
+	open ps_file, "$pscmd | grep $pid | wc -l|";
 	my $count=<ps_file>;
 	close(ps_file);
 	if($count>0) {	   
