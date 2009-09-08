--- ./Makefile.PL.orig	2009-09-08 10:45:38.000000000 +0200
+++ ./Makefile.PL	2009-09-08 10:46:38.000000000 +0200
@@ -24,19 +24,6 @@ requires    'Moose'	       =>    0.81;
 requires    'MooseX::AttributeHelpers' => 0;
 requires    'MooseX::POE'      =>    0.205;
 
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
 # Thanks to Matt Trout for this tip
 #makemaker_args(dist => { PREOP => "$^X ./tools/svn-log.perl > ./Changes" });
 makemaker_args(dist => { PREOP => "git --no-pager log --tags > ./Changes" });
