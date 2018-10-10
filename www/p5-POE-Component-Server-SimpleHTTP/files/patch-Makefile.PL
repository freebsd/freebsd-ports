--- Makefile.PL.orig	2018-09-17 10:24:28 UTC
+++ Makefile.PL
@@ -65,8 +65,8 @@ my %FallbackPrereqs = (
 );
 
 # inserted by Dist::Zilla::Plugin::DynamicPrereqs 0.034
-test_requires('POE::Component::Client::HTTP', '0.82') if prompt_default_no('Do you want to test streaming ( requires POE::Component::Client::HTTP )');
-requires('POE::Component::SSLify', '0.04') if prompt_default_no('Do you want SSL support ( requires POE::Component::SSLify )');
+test_requires('POE::Component::Client::HTTP', '0.82'); # if prompt_default_no('Do you want to test streaming ( requires POE::Component::Client::HTTP )');
+requires('POE::Component::SSLify', '0.04'); # if prompt_default_no('Do you want SSL support ( requires POE::Component::SSLify )');
 
 
 unless ( eval { ExtUtils::MakeMaker->VERSION(6.63_03) } ) {
