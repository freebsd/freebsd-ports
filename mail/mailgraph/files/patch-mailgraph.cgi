--- mailgraph.cgi.orig	Wed Aug 29 17:06:01 2007
+++ mailgraph.cgi	Thu Sep  6 22:46:09 2007
@@ -16,8 +16,8 @@
 my $points_per_sample = 3;
 my $ypoints = 160;
 my $ypoints_err = 96;
-my $rrd = 'mailgraph.rrd'; # path to where the RRD database is
-my $rrd_virus = 'mailgraph_virus.rrd'; # path to where the Virus RRD database is
+my $rrd = '%%DATADIR%%/mailgraph.rrd'; # path to where the RRD database is
+my $rrd_virus = '%%DATADIR%%/mailgraph_virus.rrd'; # path to where the Virus RRD database is
 my $tmp_dir = '/tmp/mailgraph'; # temporary directory where to store the images
 
 my @graphs = (
@@ -163,7 +163,7 @@
 <title>Mail statistics for $host</title>
 <meta http-equiv="Refresh" content="300" />
 <meta http-equiv="Pragma" content="no-cache" />
-<link rel="stylesheet" href="mailgraph.css" type="text/css" />
+<link rel="stylesheet" href="/mailgraph/mailgraph.css" type="text/css" />
 </head>
 <body>
 HEADER
