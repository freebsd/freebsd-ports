--- ljpms.pl.bak	2007-10-02 19:33:33.000000000 +0400
+++ ljpms.pl	2007-12-29 20:39:00.000000000 +0300
@@ -330,7 +330,7 @@
 
 sub make_message {
 	my ($entry) = @_;
-	my ($year, $month, $day, $hour, $min) = split(/\D+/, ($entry->{'eventtime'} or $entry->{'logtime'}));
+	my ($year, $month, $day, $hour, $min) = split(/\D+/, ($entry->{'logtime'} or $entry->{'eventtime'}));
 	my $soap_message = {
 			'ver'			=> 1,
 			'lineendings'	=> "\n",
