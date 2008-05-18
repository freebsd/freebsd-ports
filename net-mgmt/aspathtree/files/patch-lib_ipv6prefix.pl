
$FreeBSD$

--- lib/ipv6prefix.pl.orig
+++ lib/ipv6prefix.pl
@@ -12,8 +12,101 @@
 #	 output = 4 stands for the 6to4 prefix
 #	 output = 5 stands for 6to4 prefixes longer than /16
 #
+
+use strict;
+
+# Order matters! Less specific prefixes first.
+my @prefix_list = (
+#	prefix				=> min_lenght, max_len, valid_code, unaggr_code
+	[ '3FFE::/16'		=> 24, 32, 0, 0 ],
+	[ '2001::/3'		=> 19, 32, 3, 2 ],
+	[ '2001:0478::/32'	=> 40, 48, 3, 2 ],	# ep.net IX assignments
+	[ '2001:0500::/30'	=> 48, 48, 3, 2 ],	# ARIN microallocations
+	[ '2001:07F8::/32'	=> 48, 48, 3, 2 ],	# RIPE IX assignments
+	[ '2001:0678::/29'	=> 48, 48, 3, 2 ],	
+	[ '2001:0c00::/23'	=> 48, 48, 3, 2 ],	
+	[ '2001:13c7:6000::/36'	=> 36, 48, 3, 2 ],	
+	[ '2001:13c7:7000::/36'	=> 36, 48, 3, 2 ],	
+	[ '2001:43f8::/29'	=> 40, 48, 3, 2 ],	
+	[ '2002::/16'		=> 16, 16, 4, 5 ],
+);
+
 sub check_prefix {
 	my ($prefix) = @_;
+
+	my ($net, $len) = split(m#/#, $prefix);
+	my $return = 0;
+	foreach my $pref (@prefix_list) {
+		next unless $len >= $pref->[1];
+		next unless includedprefix($prefix, $pref->[0]);
+		if ($len > $pref->[2]) {
+			$return = $pref->[4];
+		} else {
+			$return = $pref->[3];
+		}
+	}
+
+	return $return;
+}
+
+# Tell whether first arg is contained in second.
+sub includedprefix {
+	use integer;
+
+	my ($a1, $l1) = split(m#/#, $_[0]);
+	my ($a2, $l2) = split(m#/#, $_[1]);
+
+	return 0 if $l1 < $l2;
+
+	my @a1 = expand($a1);
+	my @a2 = expand($a2);
+
+	# Check parts which have to be identical
+	my $end = $l2 / 16;
+	my $i;
+	for ($i = 0; $i < $end; ++$i) {
+	    return 0 if hex($a1[$i]) != hex($a2[$i]);
+	}
+
+	# Check last part
+	my $nbits = 16 - $l2 % 16;
+	return 0 if (hex($a1[$i]) >> $nbits) != (hex($a2[$i]) >> $nbits);
+
+	return 1;
+}
+
+# Expand :: and split the different 16-bit address parts
+sub expand {
+	my ($ip) = @_;
+  
+	return split(/:/, $ip) if not $ip =~ /::/;
+  
+	$ip =~ s/^::/0::/;
+	$ip =~ s/::$/::0/;
+	my ($l, $r) = split(/::/, $ip);
+	my @l = split(/:/, $l);
+	my @r = split(/:/, $r);
+	my @m;
+	for (my $i = 0; $i < 8 - length (@l) - length (@r); ++$i) {
+		push(@m, 0);
+	}
+	return (@l, @m, @r);
+}
+
+sub normal {
+	my ($ip, $len) = split(m#/#, $_[0]);
+
+	my $n = join(':', map { ('0' x (4 - length $_)) . $_ } expand($ip));
+	$n =~ s/(:0000)+/::/;
+	$n =~ s/^0000:::/::/;
+	return "$n/$len";
+}
+
+1;
+
+__END__
+sub OLD_check_prefix {
+	my ($prefix) = @_;
 	my ($normprefix, $addr, $lprefix, $conflprefix, $output, $hexprefix);
 	$normprefix = &normal($prefix);
 	($addr,$lprefix) = split(/\//,$normprefix);
