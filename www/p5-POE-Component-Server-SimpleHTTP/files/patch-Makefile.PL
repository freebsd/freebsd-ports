--- ./Makefile.PL.orig	Sun Jan  7 11:18:22 2007
+++ ./Makefile.PL	Wed Jan 10 20:07:51 2007
@@ -17,19 +17,4 @@
 requires	'HTTP::Request'			=>	0;
 requires	'HTTP::Response'		=>	0;
 
-# Ask users if they want SSL support
-my $value = prompt( 'Do you want SSL support ( requires POE::Component::SSLify ) [Y/n]?', 'N' );
-
-# Add to the prereqs PoCo::SSLify?
-if ( $value =~ /^Y$/i ) {
-	requires 'POE::Component::SSLify' => '0.04';
-}
-
-# Ask users if they want PreFork support
-$value = prompt( 'Do you want PreFork support ( requires IPC::Shareable ) [Y/n]?', 'N' );
-
-# Add to the prereqs IPC::Shareable?
-if ( $value =~ /^Y$/i ) {
-	requires 'IPC::Shareable' => '0';
-}
 WriteAll();
