--- t/03-openlive.t.orig	2007-12-22 10:46:39.000000000 -0900
+++ t/03-openlive.t	2012-04-05 16:45:58.000000000 -0800
@@ -64,8 +64,10 @@
 is(   $@,   '', "open_live()" );
 if($^O eq 'MSWin32' or $^O eq 'cygwin') {
     like( $err, '/^Error opening adapter:/', " - \$err must be set: $err" );
-} elsif($^O eq 'darwin' or $^O eq 'freebsd' or $^O eq 'openbsd') {
+} elsif($^O eq 'darwin' or $^O eq 'openbsd') {
     like( $err, "/^(?:BIOCSETIF: )?$fakedev: Device not configured/", " - \$err must be set: $err" );
+} elsif($^O eq 'freebsd') {
+    is( $err, ''); # Since pcap 1.0.0 nonexisting gives empty string.
 } else {
     like( $err, '/^(?:bind|ioctl|SIOCGIFHWADDR): (?:No such device)/', " - \$err must be set: $err" );
 }
