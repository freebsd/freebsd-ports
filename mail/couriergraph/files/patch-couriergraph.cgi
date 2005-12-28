--- couriergraph.cgi.orig	Thu Dec 29 07:42:00 2005
+++ couriergraph.cgi	Thu Dec 29 07:44:42 2005
@@ -18,9 +18,10 @@
 my $points_per_sample = 3;
 my $ypoints = 160;
 my $ypoints_err = 96;
-my $rrd = '/etc/postfix/couriergraph.rrd'; # path to where the RRD database is
-my $rrd_virus = '/etc/postfix/mailgraph_virus.rrd'; # path to where the Virus RRD database is
+my $rrd = '%%DATADIR%%/etc/postfix/couriergraph.rrd'; # path to where the RRD database is
+my $rrd_virus = '%%DATADIR%%/etc/postfix/mailgraph_virus.rrd'; # path to where the Virus RRD database is
 my $tmp_dir = '/tmp/couriergraph'; # temporary directory where to store the images
+my $rrdtool_1_0 = ($RRDs::VERSION < 1.199908);
 
 my @graphs = (
 	{ title => 'Day Graphs',   seconds => 3600*24,        },
