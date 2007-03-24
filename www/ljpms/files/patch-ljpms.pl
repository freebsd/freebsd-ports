--- ljpms.pl.orig	Fri Nov 17 17:12:34 2006
+++ ljpms.pl	Sat Mar 24 22:53:07 2007
@@ -217,7 +217,6 @@
 
 sub post_event {
 	my ($entry) = @_;
-	my ($year, $month, $day, $hour, $min) = split(/\D+/, my_encode($entry->{'eventtime'}));
 
 	my $soap_message = &make_message($entry);
 	$soap_message->{'props'}->{'opt_backdated'} = 1;
@@ -243,7 +242,7 @@
 
 sub make_message {
 	my ($entry) = @_;
-	my ($year, $month, $day, $hour, $min) = split(/\D+/, ($entry->{'eventtime'} or $entry->{'logtime'}));
+	my ($year, $month, $day, $hour, $min) = split(/\D+/, ($entry->{'logtime'} or $entry->{'eventtime'}));
 	my $soap_message = {
 			'ver'			=> 1,
 			'lineendings'	=> "\n",
