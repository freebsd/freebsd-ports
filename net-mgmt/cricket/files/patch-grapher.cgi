--- grapher.cgi.orig	2014-08-01 19:00:52.520583589 -0500
+++ grapher.cgi	2014-08-01 19:01:57.223574944 -0500
@@ -1490,6 +1490,7 @@
         # things we pick up form the target dict
         my($rrd) = $targRef->{'rrd-datafile'};
         $lasttime = scalar(localtime(RRDs::last($rrd)));
+        $lasttime =~ s/:/\\:/g;
 
         # use the dslist to create a set of defs/cdefs
 
