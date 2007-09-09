--- ovs.cgi.orig	Mon Sep  3 18:19:22 2007
+++ ovs.cgi	Fri Sep  7 20:28:39 2007
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
@@ -310,7 +310,7 @@
 <title>Mail statistics for $host</title>
 <meta http-equiv="Refresh" content="300" />
 <meta http-equiv="Pragma" content="no-cache" />
-<link rel="stylesheet" href="ovs.css" type="text/css" />
+<link rel="stylesheet" href="/ovs/ovs.css" type="text/css" />
 </head>
 <body>
 HEADER
