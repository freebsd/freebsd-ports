--- bsmonitor/Statusmon/bs_evgen.pm.orig	Sat Feb 28 16:47:57 2004
+++ bsmonitor/Statusmon/bs_evgen.pm	Sat Feb 28 16:47:30 2004
@@ -405,7 +405,7 @@
     elsif( $event->{"cmd"} eq "remove" ) {
 	my $host = $event->{"host"};
 	my $check = $event->{"check"};
-	foreach my $queuename qw( alarms new_alarms old_alarms ) {
+	foreach my $queuename (qw( alarms new_alarms old_alarms )) {
 	    my $queue = $self->{$queuename};
 	    for( my $i=$#$queue; $i>=0; $i-- ) {
 	        my $alarm = $queue->[$i];
