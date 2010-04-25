--- lib/Video/DVDRip/Cluster/Master.pm.orig	2010-04-24 17:21:50.000000000 -0300
+++ lib/Video/DVDRip/Cluster/Master.pm	2010-04-24 17:25:30.000000000 -0300
@@ -122,7 +122,7 @@
 sub check_prerequisites {
     my $class = shift;
 
-    foreach my $path ( "/usr/bin", "/usr/sbin" ) {
+    foreach my $path ( "/usr/bin", "/usr/sbin", "/usr/local/sbin" ) {
         if ( -f "$path/fping" and -x "$path/fping" ) {
             $FPING = "$path/fping";
             last;
