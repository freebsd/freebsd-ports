Add fix from https://github.com/schweikert/mailgraph/pull/23: ("removed version checks to tackle rrdtool pr #1331 - #23")

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
@@ -43,7 +43,7 @@
 	# choose carefully the end otherwise rrd will maybe pick the wrong RRA:
 	my $end  = time; $end -= $end % $step;
 	my $date = localtime(time);
-	$date =~ s|:|\\:|g unless $RRDs::VERSION < 1.199908;
+	$date =~ s|:|\\:|g;
 
 	my ($graphret,$xs,$ys) = RRDs::graph($file,
 		'--imgformat', 'PNG',
@@ -59,14 +59,14 @@
 		'--color', 'SHADEB#ffffff',
 		'--color', 'BACK#ffffff',
 
-		$RRDs::VERSION < 1.2002 ? () : ( '--slope-mode'),
+		'--slope-mode',
 
 		@rrdargs,
 
 		'COMMENT:['.$date.']\r',
 	);
 
-	my $ERR=RRDs::error;
+	my $ERR = RRDs::error;
 	die "ERROR: $ERR\n" if $ERR;
 }
 
@@ -163,7 +163,7 @@
 <title>Mail statistics for $host</title>
 <meta http-equiv="Refresh" content="300" />
 <meta http-equiv="Pragma" content="no-cache" />
-<link rel="stylesheet" href="mailgraph.css" type="text/css" />
+<link rel="stylesheet" href="/mailgraph/mailgraph.css" type="text/css" />
 </head>
 <body>
 HEADER
@@ -185,10 +185,10 @@
 	print <<FOOTER;
 <hr/>
 <table><tr><td>
-<a href="http://mailgraph.schweikert.ch/">Mailgraph</a> $VERSION
-by <a href="http://david.schweikert.ch/">David Schweikert</a></td>
+<a href="https://mailgraph.schweikert.ch/">Mailgraph</a> $VERSION
+by <a href="https://david.schweikert.ch/">David Schweikert</a></td>
 <td align="right">
-<a href="http://oss.oetiker.ch/rrdtool/"><img src="http://oss.oetiker.ch/rrdtool/.pics/rrdtool.gif" alt="" width="120" height="34"/></a>
+<a href="https://oss.oetiker.ch/rrdtool/"><img src="https://oss.oetiker.ch/rrdtool/.pics/rrdtool.gif" alt="" width="120" height="34"/></a>
 </td></tr></table>
 </body></html>
 FOOTER
