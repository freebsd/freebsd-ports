--- Makefile.PL.orig	Mon Aug 18 03:35:42 2003
+++ Makefile.PL	Fri Oct  3 11:47:30 2003
@@ -5,28 +5,7 @@
 use constant FLAG_SKIPMECHDUMP => "t/SKIP-MECH-FORMS";
 
 # Much logic stolen fromm libwww-perl's Makefile.PL
-my $skiplive = 0;
-
-require IO::Socket;
-my $s = IO::Socket::INET->new(PeerAddr => "www.google.com:80",
-			      Timeout  => 10,
-			     );
-if ($s) {
-    close($s);
-    $skiplive = 0;
-} else {
-    print <<EOT;
-
-It seems that you are not directly connected to the Internet.  Some
-of the WWW::Mechanize tests interact with websites such as Google,
-in addition to its own internal tests.
-
-EOT
-
-    if ( prompt("Do you want to skip these tests?", "y") =~ /^y/i ) {
-	$skiplive = 1;
-    }
-} # failed connect
+my $skiplive = 1;
 
 my $tests = 't/*.t';
 $tests .= ' t/live/*.t' unless $skiplive;
@@ -53,17 +32,17 @@
     'test' => { TESTS => $tests },
 };
 
-if ( prompt( "Do you want to install the mech-dump utility?", "y" ) =~ /^y/i ) {
+#if ( prompt( "Do you want to install the mech-dump utility?", "y" ) =~ /^y/i ) {
     $parms->{EXE_FILES} = [ 'script/mech-dump' ];
     $parms->{PREREQ_PM}->{'Getopt::Long'} = 0;
     $parms->{PREREQ_PM}->{'Pod::Usage'} = 0;
 
-    local @ARGV = FLAG_SKIPMECHDUMP;
+    local @ARGV = (@ARGV, FLAG_SKIPMECHDUMP);
     rm_f();
-} else {
-    local @ARGV = FLAG_SKIPMECHDUMP;
-    touch();
-}
+#} else {
+#    local @ARGV = FLAG_SKIPMECHDUMP;
+#    touch();
+#}
 
 
 eval { require IO::Socket::SSL };
