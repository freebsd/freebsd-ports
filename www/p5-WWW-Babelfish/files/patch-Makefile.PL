--- Makefile.PL.orig	Tue Sep  6 10:02:11 2005
+++ Makefile.PL	Tue Sep  6 10:02:27 2005
@@ -1,27 +1,4 @@
 use ExtUtils::MakeMaker;
-use IO::Socket;
-
-# Check if we have internet connection
-# (I lifted this code from Net::DNS)
-my $s = IO::Socket::INET->new(
-        PeerAddr => "www.cpan.org:80",
-        Timeout  => 10,
-);
-
-if($s){
-  if (prompt("Since you're connected to the internet, do you want to run a translation test?", "n") =~ /^y/i) {
-    open(ENABLED, ">TTEST") || die "Can't touch ./t/online.enabled $!";
-    close(ENABLED);
-  }
-  else {
-    unlink("TTEST");
-  }
-}
-else{
-  print "You're not connected to the internet, so we'll skip the translation test.\n\n";
-  unlink("TTEST");
-}
-close($s);
 
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
