--- mailgraph.cgi.orig	Sat Feb  7 21:48:52 2004
+++ mailgraph.cgi	Mon Apr 12 02:45:53 2004
@@ -15,8 +15,8 @@
 my $points_per_sample = 3;
 my $ypoints = 150;
 my $ypoints_err = 80;
-my $rrd = 'mailgraph.rrd'; # path to where the RRD database is
-my $rrd_virus = 'mailgraph_virus.rrd'; # path to where the Virus RRD database is
+my $rrd = '%%DATADIR%%/mailgraph.rrd'; # path to where the RRD database is
+my $rrd_virus = '%%DATADIR%%/mailgraph_virus.rrd'; # path to where the Virus RRD database is
 my $tmp_dir = '/tmp/mailgraph'; # temporary directory where to store the images
 
 my @graphs = (
