--- mailgraph.cgi.orig	Sun Jul 11 23:57:06 2004
+++ mailgraph.cgi	Tue Jul 13 23:13:48 2004
@@ -15,8 +15,8 @@
 my $points_per_sample = 3;
 my $ypoints = 160;
 my $ypoints_err = 96;
-my $rrd = 'mailgraph.rrd'; # path to where the RRD database is
-my $rrd_virus = 'mailgraph_virus.rrd'; # path to where the Virus RRD database is
+my $rrd = '%%DATADIR%%/mailgraph.rrd'; # path to where the RRD database is
+my $rrd_virus = '%%DATADIR%%/mailgraph_virus.rrd'; # path to where the Virus RRD database is
 my $tmp_dir = '/tmp/mailgraph'; # temporary directory where to store the images
 
 my @graphs = (
