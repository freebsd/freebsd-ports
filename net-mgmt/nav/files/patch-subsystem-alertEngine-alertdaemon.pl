--- subsystem/alertEngine/alertdaemon.pl.orig	Wed Apr 28 15:03:41 2004
+++ subsystem/alertEngine/alertdaemon.pl	Thu Nov 11 12:13:15 2004
@@ -37,9 +37,16 @@
 use IO::Handle;
 
 use Engine;
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
@@ -65,7 +72,7 @@
 		die "Cannot open pidfile";
 	    my ($pid, $tid) = split / /, <pid_file>;
 	    close(pid_file);
-	    open ps_file, "ps -e | grep $pid | wc -l|";
+	    open ps_file, "$pscmd | grep $pid | wc -l|";
 	    my $count=<ps_file>;
 	    close(ps_file);
 	    if($count==0) {
@@ -144,7 +151,7 @@
 			die "Cannot open pidfile";
 		my ($pid, $tid) = split / /, <pid_file>;
 		close(pid_file);
-		open ps_file, "ps -e | grep $pid | wc -l|";
+		open ps_file, "$pscmd | grep $pid | wc -l|";
 		my $count=<ps_file>;
 		close(ps_file);
 		if($count==0) {
@@ -179,7 +186,7 @@
 	    die "Cannot open pidfile";
 	my ($pid, $tid) = split / /, <pid_file>;
 	close(pid_file);
-	open ps_file, "ps -e | grep $pid | wc -l|";
+	open ps_file, "$pscmd | grep $pid | wc -l|";
 	my $count=<ps_file>;
 	close(ps_file);
 	if($count>0) {	   
