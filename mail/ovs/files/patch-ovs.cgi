--- ovs.cgi.old	Sun Aug 26 23:55:10 2007
+++ ovs.cgi	Sun Aug 26 23:56:44 2007
@@ -25,9 +25,9 @@
 my $points_per_sample = 3;
 my $ypoints = 160;
 my $ypoints_err = 260;
-my $rrd = 'ovs.rrd';		 # path to where the RRD database is
-my $rrd_virus = 'ovs_virus.rrd'; # path to where the Virus RRD database is
-my $rrd_pop = 'ovs_pop.rrd';	 # path to where the Virus RRD database is
+my $rrd = '%%DATADIR%%/ovs.rrd';		 # path to where the RRD database is
+my $rrd_virus = '%%DATADIR%%/ovs_virus.rrd'; # path to where the Virus RRD database is
+my $rrd_pop = '%%DATADIR%%/ovs_pop.rrd';	 # path to where the Virus RRD database is
 my $tmp_dir = '/tmp/ovs';	 # temporary directory where to store the images
 
 my @graphs = (
