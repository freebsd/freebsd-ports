--- Makefile.PL.orig	2020-11-17 10:01:32 UTC
+++ Makefile.PL
@@ -7,17 +7,12 @@ use strict;
 use warnings;
 
 use ExtUtils::MakeMaker 6.52;
-use Alien::Base::Wrapper 2.02;
 
 my @build = (
-    alien_requires => {
-        'Alien::TidyHTML5' => '0.3.0',
-    },
 );
 
 my $parms = {
     CONFIGURE_REQUIRES => {
-        'Alien::Base::Wrapper' => '2.02',
     },
     NAME          => 'HTML::T5',
     AUTHOR        => 'Andy Lester <andy@petdance.com>',
@@ -42,8 +37,6 @@ my $parms = {
         prereqs => {
             configure => {
                 'Devel::CheckLib'      => 0,
-                'Alien::Base::Wrapper' => 0,
-                'Alien::TidyHTML5'     => 0,
             },
         },
         resources => {
@@ -64,11 +57,7 @@ my $parms = {
     dist      => { COMPRESS => 'gzip -9f', SUFFIX => 'gz', },
     clean     => { FILES => 'HTML-T5-*' },
 };
-
-my %foo =
-    Alien::Base::Wrapper->new('Alien::TidyHTML5=0.3.0')->mm_args2(%$parms);
-$foo{CONFIGURE_REQUIRES}{'Alien::Base::Wrapper'} = '2.02';
-WriteMakefile(%foo);
+WriteMakefile();
 
 sub MY::postamble
 {    ## no critic ( Subroutines::ProhibitQualifiedSubDeclarations )
