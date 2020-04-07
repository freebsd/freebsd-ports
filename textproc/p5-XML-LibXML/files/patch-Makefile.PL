--- Makefile.PL.orig	2020-03-17 16:32:19 UTC
+++ Makefile.PL
@@ -17,13 +17,10 @@ use warnings;
 
 require 5.008001;
 
-use Alien::Base::Wrapper qw( Alien::Libxml2 );
 use ExtUtils::MakeMaker;
 use Config;
 
 my %ConfigReqs = (
-  "Alien::Libxml2" => '0.14',
-  "Alien::Base::Wrapper" => 0,
   "Config" => 0,
   "ExtUtils::MakeMaker" => 0,
 );
@@ -69,7 +66,9 @@ my %prereqs = (
 my %xsbuild = (
   DEFINE  => '-DHAVE_UTF8',
   OBJECT  => '$(O_FILES)',
-  Alien::Base::Wrapper->mm_args,
+  CCFLAGS => " $Config{ccflags}",
+  INC     => "-I$ENV{LOCALBASE}/include/libxml2 -I/usr/include",
+  LIBS    => "-L$ENV{LOCALBASE}/lib -lxml2 -L/usr/lib -llzma -lm -lz",
 );
 
 my %WriteMakefileArgs = (
