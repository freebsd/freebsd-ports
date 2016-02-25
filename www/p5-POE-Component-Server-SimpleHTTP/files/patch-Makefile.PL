--- Makefile.PL.orig	2013-07-02 20:20:09 UTC
+++ Makefile.PL
@@ -23,19 +23,6 @@ requires    'HTTP::Response'   =>    0;
 requires    'Moose'	       =>    0.90;
 requires    'MooseX::POE'      =>    0.205;
 
-build_requires   'Test::More'                   => 0.47;
-build_requires	 'POE::Filter::HTTP::Parser'	=> 1.06;
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
 # Thanks to Matt Trout for this tip
 makemaker_args(dist => { PREOP => "$^X tools/git-log.pl > ./Changes" });
 
