--- lib/Text/Reform.pm.orig	Wed Apr  9 10:49:02 2003
+++ lib/Text/Reform.pm	Fri May  2 14:47:28 2003
@@ -44,7 +43,7 @@
 }
 
 sub carpfirst {
-	our %carped;
+	my %carped;
 	my ($msg) = @_;
 	return if $carped{$msg}++;
 	carp $msg;
@@ -342,8 +341,7 @@
 
 sub form
 {
-	our %carped;
-	local %carped;
+	my %carped;
 	my $config = {%std_config};
 	my $startidx = 0;
 	if (@_ && ref($_[0]) eq 'HASH')		# RESETTING CONFIG
