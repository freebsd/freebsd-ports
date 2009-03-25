--- ./Makefile.PL.orig	2009-03-17 10:45:12.000000000 +0100
+++ ./Makefile.PL	2009-03-17 10:46:05.000000000 +0100
@@ -20,28 +20,6 @@ requires    'Socket'           =>    0;
 requires    'HTTP::Request'    =>    0;
 requires    'HTTP::Response'   =>    0;
 
-build_requires   'Test::More'                   => 0.47;
-build_requires	 'POE::Filter::HTTP::Parser'	=> 0.02;
-build_requires	 'Test::POE::Client::TCP'	=> 0.10;
-
-my $value = prompt( 'Do you want to test streaming ( requires POE::Component::Client::HTTP ) [y/N]?', 'N' );
-build_requires   'POE::Component::Client::HTTP' => 0.82 if $value =~ /^Y$/i;
-
-# Ask users if they want SSL support
-$value = prompt( 'Do you want SSL support ( requires POE::Component::SSLify ) [y/N]?', 'N' );
-
-# Add to the prereqs PoCo::SSLify?
-requires 'POE::Component::SSLify' => '0.04' if $value =~ /^Y$/i;
-
-# Ask users if they want PreFork support
-$value = prompt( 'Do you want PreFork support ( requires IPC::Shareable ) [y/N]?', 'N' );
-
-# Add to the prereqs IPC::Shareable?
-if ( $value =~ /^Y$/i ) {
-   requires 'IPC::Shareable' => '0';
-   build_requires   'POE::Component::Client::HTTP' => 0.82;
-}
-
 # Sanity check
 eval { require IPC::Shareable; };
 build_requires 'POE::Component::Client::HTTP' => 0.82 unless $@;
