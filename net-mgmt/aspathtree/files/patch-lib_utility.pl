
$FreeBSD$

--- lib/utility.pl.orig
+++ lib/utility.pl
@@ -139,10 +139,35 @@
 	return($text);
 }
 
+my $IPv6PrefixTable;
+
+sub read_prefixtable {
+	my ($file) = @_;
+
+	open(FILE, $file) or die "Cannot open $file: $!";
+	while (<FILE>) {
+		my ($site, @prefixes) = split;
+		foreach my $prefix (@prefixes) {
+			$IPv6PrefixTable->{$prefix} = $site;
+		}
+	}
+	close FILE;
+
+	return $IPv6PrefixTable;
+}
+
 # Routine to find the owner site name of a prefix
 sub extract_name_from_prefix {
 	my ($prefix) = @_;
 
+	$IPv6PrefixTable ||= read_prefixtable($IPV6PREFIXTABLE);
+	return $IPv6PrefixTable->{$prefix} || '?';
+}
+
+# Routine to find the owner site name of a prefix
+sub OLD_extract_name_from_prefix {
+	my ($prefix) = @_;
+
 	my ($line, $sitename) = ('', '');
 
 	open(FILE,"<".$IPV6PREFIXTABLE);
@@ -377,7 +402,7 @@
 	my @outwhois = ();
 	my @coomands = ();
 
-	my $command = "-h whois.ripe.net -s ARIN,RIPE,APNIC -r -T inet6num -M 2001::/16";
+	my $command = "-h whois.ripe.net -s ARIN,RIPE,APNIC -r -T inet6num -M 2001::/3";
 	push (@commands, $command);
 
 	open(WHOISRES,"$RIPEWHOISCLIENT $command |");
@@ -547,8 +572,63 @@
 	return($ias);
 }
 
+my ($ASLines, $BBSites);
+
+sub read_astable {
+	my ($file) = @_;
+
+	open(FILE, $file) or die "Cannot open $file: $!";
+	while (<FILE>) {
+		my ($asn, $sites) = split(/\s+/, $_, 2);
+		$asn =~ s/^AS//;
+		$ASLines->{$asn} = $sites;
+	}
+	close FILE;
+
+	return $ASLines;
+}
+
+sub read_ptlafile {
+	my ($file) = @_;
+
+	open(FILE, $file) or die "Cannot open $file: $!";
+	while (<FILE>) {
+		my ($site, $prefix) = split;
+		$BBSites->{$site} = $prefix;
+	}
+	close FILE;
+
+	return $BBSites;
+}
+
 # Routine to associate the name of the owner organisation to an AS number
 sub asntosite {
+	my ($asn, $astable, $ptlastable) = @_;
+
+	$ASLines ||= read_astable($astable);
+	$BBSites ||= read_ptlafile($ptlastable);
+
+	my $sites = $ASLines->{$asn};
+	return (-1, ()) if not $sites;
+
+	my @tmp = split(/\s+/, $sites);
+	my @output;
+	my $nbb = 0;
+
+	foreach my $name (@tmp) {
+		if (exists $BBSites->{$name}) {
+			$nbb++;
+			unshift(@output, $name);
+		} else {
+			push(@output, $name);
+		}
+	}
+
+	return ($nbb, @output);
+}
+
+# Routine to associate the name of the owner organisation to an AS number
+sub OLD_asntosite {
 	my ($ASN, $astable, $ptlastable) = @_;
 	my (@aslines, @bb_sites, @output, @tmp);
 	my ($key, $line, $name, $nbb);
