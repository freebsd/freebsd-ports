--- At.pm.orig	Mon Mar 25 20:52:01 2002
+++ At.pm	Tue May 14 17:17:41 2002
@@ -258,6 +258,7 @@
 Jose A. Rodriguez (josear@ac.upc.es)
 
 =cut
+#' for Emacs face
 
 ###############################################################################
 # OS dependent code
@@ -327,6 +328,25 @@
 		my @fields = split("\t", $_[0]);
 		($fields[0], substr($fields[1], 0, 16)) 
 	};
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
+	  sub {
+	    my @a = split(/\s+/, $_[0]);
+	    if (/^\d\d/) {
+	      return ($a[4], "$a[0] $a[1]");
+	    } elsif (defined $a[8]) {
+	      return ($a[8], "$a[0] $a[1] $a[2] $a[3] $a[4] $a[5]");
+	    }
+	  };
 }
 
 sub AtCfg_aix {
