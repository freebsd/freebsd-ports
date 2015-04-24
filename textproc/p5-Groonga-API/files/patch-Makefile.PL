--- Makefile.PL.orig	2015-04-24 21:40:21 UTC
+++ Makefile.PL
@@ -2,7 +2,7 @@ use strict;
 use warnings;
 use FindBin;
 use inc::GroongaAPIUtil;
-use ExtUtils::MakeMaker::CPANfile;
+use ExtUtils::MakeMaker;
 
 my $env = inc::GroongaAPIUtil::check_env() or exit 0; # N/A
 inc::GroongaAPIUtil::write_files($env);
