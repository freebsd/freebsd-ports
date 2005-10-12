--- Makefile.PL.orig	Wed Oct 12 11:21:00 2005
+++ Makefile.PL	Wed Oct 12 11:21:16 2005
@@ -16,22 +16,6 @@
 	'HTTP::Response'		=>	0,
 };
 
-# Ask users if they want SSL support
-my $value = prompt( 'Do you want SSL support ( requires POE::Component::SSLify ) [Y/n]?', 'Y' );
-
-# Add to the prereqs PoCo::SSLify?
-if ( $value =~ /^Y$/i ) {
-	$prereqs->{ 'POE::Component::SSLify' } = '0.04';
-}
-
-# Ask users if they want PreFork support
-$value = prompt( 'Do you want PreFork support ( requires IPC::Shareable ) [Y/n]?', 'Y' );
-
-# Add to the prereqs IPC::Shareable?
-if ( $value =~ /^Y$/i ) {
-	$prereqs->{ 'IPC::Shareable' } = '0';
-}
-
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
 WriteMakefile(
