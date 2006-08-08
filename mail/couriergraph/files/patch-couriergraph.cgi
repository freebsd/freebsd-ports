--- couriergraph.cgi.orig	Tue Aug  8 11:56:47 2006
+++ couriergraph.cgi	Tue Aug  8 11:57:09 2006
@@ -18,7 +18,7 @@
 my $points_per_sample = 3;
 my $ypoints = 160;
 my $ypoints_err = 96;
-my $rrd = '/etc/postfix/couriergraph.rrd'; # path to where the RRD database is
+my $rrd = '%%DATADIR%%/couriergraph.rrd'; # path to where the RRD database is
 my $tmp_dir = '/tmp/couriergraph'; # temporary directory where to store the images
 
 my @graphs = (
