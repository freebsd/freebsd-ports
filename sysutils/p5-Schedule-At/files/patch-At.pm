--- At.pm.orig	Thu Feb 12 20:08:37 1998
+++ At.pm	Wed Jan 10 11:56:50 2001
@@ -264,6 +264,7 @@
 Jose A. Rodriguez (josear@ac.upc.es)
 
 =cut
+#' for Emacs face
 
 ###############################################################################
 # OS dependent code
@@ -330,4 +331,16 @@
 	$AT{'getCommand'} = 'at -c %JOBID% |';
 	$AT{'parseJobList'} = 
 		sub { (substr($_[0], 27), substr($_[0], 0, 17)) } ;
+}
+
+sub AtCfg_freebsd {
+	$AT{'add'} = 'at %TIME% 2> /dev/null';
+	$AT{'addFile'} = 'at -f %FILE% %TIME% 2> /dev/null';
+	$AT{'timeFormat'} = '%HOUR%:%MINS% %MONTH%/%DAY%/%YEAR%';
+	$AT{'remove'} = 'atrm %JOBID%';
+	$AT{'getJobs'} = 'atq';
+	$AT{'headings'} = ['Date'];
+	$AT{'getCommand'} = 'at -c %JOBID% |';
+	$AT{'parseJobList'} = 
+		sub { my @a = split(/\s+/, $_[0]); ($a[4], "$a[0] $a[1]") } ;
 }
