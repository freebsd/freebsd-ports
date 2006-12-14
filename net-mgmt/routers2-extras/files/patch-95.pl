--- 95.pl.orig	Thu Dec 14 16:22:04 2006
+++ 95.pl	Thu Dec 14 16:22:56 2006
@@ -0,0 +1,80 @@
+#!%%PERL%%
+
+use strict;
+use Getopt::Long;
+
+# Options 
+my %option;
+
+sub usage 
+{
+	print <<"EOA"
+usage: 95 --rrd=/path/to/rrdfile.rdd
+	--rrd=file	rrdfile to be used to compute the 95 percentil
+	--help		this help
+	-h		this help
+EOA
+}
+
+sub main
+{
+	my $rrd;
+	my $line;
+	my $value;
+	my $percentile95;
+	my $percentile95i;
+	my $percentile95o;
+	my @rrdfetch;
+	my @allvalues;
+	my @allvaluesi;
+	my @allvalueso;
+	my $in;
+	my $out;
+	my @array;
+
+	die unless GetOptions(
+		'help|h' => \$option{'help'},
+		'rrd=s'  => \$option{'rrd'},
+	);
+
+	if ($option{'help'}) {
+		usage();
+		exit;
+	}
+
+	unless (defined $option{'rrd'} ) {
+		usage();
+		die 'rrdfile is not specified';
+	}
+
+	$rrd = $option{'rrd'};
+
+	#@rrdfetch=qx(/usr/local/bin/rrdtool fetch $rrd AVERAGE -r 300 -s -30000 -e -300);
+#	@rrdfetch=qx(/usr/local/bin/rrdtool fetch $rrd AVERAGE -r 300 -s -24h);
+#	@rrdfetch=qx(/usr/local/bin/rrdtool fetch $rrd AVERAGE -r 300 -s -24h -e -300);
+	#@rrdfetch=qx(/usr/local/bin/rrdtool fetch $rrd AVERAGE -r 300 -s -1m -e -300);
+	@rrdfetch=qx(/usr/local/bin/rrdtool fetch $rrd AVERAGE -r 300 -s -1month);
+	chomp @array;
+	foreach $line (@rrdfetch) {
+		split(/\s+/,$line);
+		$in = $_[1]; $out = $_[2];
+		#$value=($_[1] > $_[2]) ? $_[1] : $_[2];
+		$value=($in > $out) ? $in : $out;
+		push (@allvalues,$value);
+		push (@allvaluesi,$in);
+		push (@allvalueso,$out);
+	}
+
+	@allvalues=sort {$a <=> $b} @allvalues;
+	$percentile95=sprintf("%.2f",($allvalues[(sprintf("%.0f",(@allvalues*0.95))-1)]*8/1000));
+	@allvaluesi=sort {$a <=> $b} @allvaluesi;
+	$percentile95i=sprintf("%.2f",($allvaluesi[(sprintf("%.0f",(@allvaluesi*0.95))-1)]*8/1000));
+	@allvalueso=sort {$a <=> $b} @allvalueso;
+	$percentile95o=sprintf("%.2f",($allvalueso[(sprintf("%.0f",(@allvalueso*0.95))-1)]*8/1000));
+	print "In/Out : $percentile95 KBytes\n";
+	print "In     : $percentile95i KBytes\n";
+	print "Out    : $percentile95o KBytes\n";
+
+}
+
+main();
