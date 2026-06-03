Avoid using more Alien::* in ports tree.

--- Makefile.PL.orig	2026-05-20 01:29:12 UTC
+++ Makefile.PL
@@ -17,15 +17,12 @@ require 5.008001;
 
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
@@ -67,15 +64,13 @@ my %prereqs = (
   "warnings" => 0,
 );
 
-my %xsbuild_concat = (
+my %xsbuild = (
   DEFINE  => '-DHAVE_UTF8',
   OBJECT  => '$(O_FILES)',
+  CCFLAGS => " $Config{ccflags}",
+  INC     => "-I$ENV{LOCALBASE}/include/libxml2 -I/usr/include",
+  LIBS    => "-L$ENV{LOCALBASE}/lib -lxml2 -L/usr/lib -llzma -lm -lz",
 );
-my %xsbuild = Alien::Base::Wrapper->mm_args;  # Might contain a definition of DEFINE, must thus concatenate.
-while (my ($k, $v) = each %xsbuild_concat) {
-  my $base_val = $xsbuild{$k};
-  $xsbuild{$k} = (defined($base_val) ? ($base_val . ' ' . $v) : $v);
-}
 
 # Strip bogus -L/lib entries that Alien::Base::Wrapper sometimes injects
 # (the directory does not exist on macOS and the linker warns about it).
