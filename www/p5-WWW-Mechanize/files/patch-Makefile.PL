--- Makefile.PL.orig	Sun Mar 28 06:06:04 2004
+++ Makefile.PL	Fri May 21 13:02:17 2004
@@ -1,4 +1,3 @@
-require 5.6.1;
 use ExtUtils::MakeMaker qw( WriteMakefile prompt );
 use ExtUtils::Command qw( touch rm_f );
 use File::Spec;
@@ -63,7 +62,7 @@
     clean           => { FILES => join( " ", FLAG_SKIPMECHDUMP, 'WWW-Mechanize-0*' ) },
 };
 
-if ( prompt( "Do you want to install the mech-dump utility?", "y" ) =~ /^y/i ) {
+if (1 or prompt( "Do you want to install the mech-dump utility?", "y" ) =~ /^y/i ) {
     $parms->{EXE_FILES} = [ 'bin/mech-dump' ];
     $parms->{PREREQ_PM}->{'Getopt::Long'} = 0;
     $parms->{PREREQ_PM}->{'Pod::Usage'} = 0;
