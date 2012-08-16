--- fop-ttc-metric.pl.orig	2012-08-16 13:18:18.812392376 -0400
+++ fop-ttc-metric.pl	2012-08-16 13:20:03.563392637 -0400
@@ -35,7 +35,7 @@
 my $man       = undef;
 my $help      = undef;
 my $outdir    = 'font-metrics';
-my $share     = '/usr/share/publican';
+my $share     = '%%DATADIR%%';
 my $conf_file = 'datadir/fop/fop.xconf';
 use utf8;
 binmode(STDERR, ':encoding(UTF-8)');
