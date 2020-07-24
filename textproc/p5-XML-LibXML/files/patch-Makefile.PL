--- Makefile.PL.orig	2020-05-08 11:33:39 UTC
+++ Makefile.PL
@@ -17,15 +17,12 @@ use warnings;
 
 require 5.008001;
 
-use Alien::Base::Wrapper qw( Alien::Libxml2 );
 use ExtUtils::MakeMaker;
 use Config;
 
 my $SKIP_SAX_INSTALL = $ENV{SKIP_SAX_INSTALL};
 
 my %ConfigReqs = (
-  "Alien::Libxml2" => '0.14',
-  "Alien::Base::Wrapper" => 0,
   "Config" => 0,
   "ExtUtils::MakeMaker" => 0,
 );
@@ -71,7 +68,9 @@ my %prereqs = (
 my %xsbuild = (
   DEFINE  => '-DHAVE_UTF8',
   OBJECT  => '$(O_FILES)',
-  Alien::Base::Wrapper->mm_args,
+  CCFLAGS => " $Config{ccflags}",
+  INC     => "-I$ENV{LOCALBASE}/include/libxml2 -I/usr/include",
+  LIBS    => "-L$ENV{LOCALBASE}/lib -lxml2 -L/usr/lib -llzma -lm -lz",
 );
 
 my %WriteMakefileArgs = (
