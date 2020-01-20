--- Makefile.PL.orig	2020-01-13 09:13:13 UTC
+++ Makefile.PL
@@ -17,12 +17,10 @@ use warnings;
 
 require 5.008001;
 
-use Alien::Libxml2;
 use ExtUtils::MakeMaker;
 use Config;
 
 my %ConfigReqs = (
-  "Alien::Libxml2" => 0,
   "Config" => 0,
   "ExtUtils::MakeMaker" => 0,
 );
@@ -68,8 +66,9 @@ my %prereqs = (
 my %xsbuild = (
   DEFINE  => '-DHAVE_UTF8',
   OBJECT  => '$(O_FILES)',
-  CCFLAGS => Alien::Libxml2->cflags . " $Config{ccflags}",
-  LIBS    => [ Alien::Libxml2->libs ],
+  CCFLAGS => " $Config{ccflags}",
+  INC     => "-I$ENV{LOCALBASE}/include/libxml2 -I/usr/include",
+  LIBS    => "-L$ENV{LOCALBASE}/lib -lxml2 -L/usr/lib -llzma -lm -lz",
 );
 
 my %WriteMakefileArgs = (
