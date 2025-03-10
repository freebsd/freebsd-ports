--- Makefile.PL.orig	2022-03-15 09:26:21 UTC
+++ Makefile.PL
@@ -8,13 +8,11 @@ use ExtUtils::MakeMaker;
 use 5.010;
 use ExtUtils::MakeMaker;
 
-use Alien::Base::Wrapper qw( Alien::GMP !export );
 
 my %WriteMakefileArgs = (
   "ABSTRACT" => "High speed arbitrary size integer math",
   "AUTHOR" => "Shlomi Fish <shlomif\@cpan.org>",
   "CONFIGURE_REQUIRES" => {
-    "Alien::GMP" => "1.08",
     "ExtUtils::MakeMaker" => 0
   },
   "DISTNAME" => "Math-GMP",
@@ -48,7 +46,7 @@ my %WriteMakefileArgs = (
 
 %WriteMakefileArgs = (
     %WriteMakefileArgs,
-    Alien::Base::Wrapper->mm_args,
+    "LIBS" => ["-lgmp"],
 );
 
 my %FallbackPrereqs = (
