--- Load.pm	2002-09-01 09:54:44.000000000 +0000
+++ Load.pm	2011-01-19 12:07:33.000000000 +0000
@@ -17,17 +17,6 @@
 bootstrap Sys::Load $VERSION;
 
 # Preloaded methods go here.
-
-use constant UPTIME => "/proc/uptime";
-
-sub uptime {
-  open(FILE, UPTIME) || return 0;
-  my $line = <FILE>;
-  my($uptime, $idle) = split /\s+/, $line;
-  close FILE;
-  return $uptime;
-}
-
 1;
 
 __END__
