--- Makefile.PL.orig	Thu Jun  5 16:42:58 2003
+++ Makefile.PL	Fri Jun 13 16:38:15 2003
@@ -82,30 +82,30 @@
 # Check if we have internet connection
 # (I lifted this code from LWP... )
 #
-my $s = IO::Socket::INET->new(
-	PeerAddr => "www.google.com:80",
-	Timeout  => 10,
-);
+#my $s = IO::Socket::INET->new(
+#	PeerAddr => "www.google.com:80",
+#	Timeout  => 10,
+#);
 
-if ($s) {
-	close($s);
+#if ($s) {
+#	close($s);
+#
+#	print <<EOT;
 
-	print <<EOT;
+#You appear to be directly connected to the Internet.  I have some tests
+#that try to query live nameservers.
 
-You appear to be directly connected to the Internet.  I have some tests
-that try to query live nameservers.
+#EOT
 
-EOT
-
-	if (prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
-		open(ENABLED, ">t/online.enabled") || die "Can't touch ./t/online.enabled $!";
-		close(ENABLED);
-	} else {
-		unlink("t/online.enabled"); # just to be shure...
-	}
-} else {
-	unlink("t/online.enabled"); # just to be shure...
-}
+#	if (prompt("Do you want to enable these tests?", "y") =~ /^y/i) {
+#		open(ENABLED, ">t/online.enabled") || die "Can't touch ./t/online.enabled $!";
+#		close(ENABLED);
+#	} else {
+#		unlink("t/online.enabled"); # just to be shure...
+#	}
+#} else {
+#	unlink("t/online.enabled"); # just to be shure...
+#}
 
 
 WriteMakefile(%Makefile);
