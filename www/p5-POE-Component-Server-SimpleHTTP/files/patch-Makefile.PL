--- ./Makefile.PL.orig	Thu Mar 22 20:26:42 2007
+++ ./Makefile.PL	Thu Mar 22 20:27:01 2007
@@ -17,22 +17,4 @@
 requires    'HTTP::Request'    =>    0;
 requires    'HTTP::Response'   =>    0;
 
-build_requires   'Test::More'                   =>    0;
-build_requires   'POE::Component::Client::HTTP' =>    0;
-
-# Ask users if they want SSL support
-my $value = prompt( 'Do you want SSL support ( requires POE::Component::SSLify ) [Y/n]?', 'N' );
-
-# Add to the prereqs PoCo::SSLify?
-if ( $value =~ /^Y$/i ) {
-    requires 'POE::Component::SSLify' => '0.04';
-}
-
-# Ask users if they want PreFork support
-$value = prompt( 'Do you want PreFork support ( requires IPC::Shareable ) [Y/n]?', 'N' );
-
-# Add to the prereqs IPC::Shareable?
-if ( $value =~ /^Y$/i ) {
-    requires 'IPC::Shareable' => '0';
-}
 WriteAll();
