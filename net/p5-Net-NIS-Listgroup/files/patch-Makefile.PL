--- Makefile.PL.orig	2013-11-05 23:28:52.000000000 +0800
+++ Makefile.PL	2013-11-05 23:29:05.000000000 +0800
@@ -54,7 +54,7 @@ my $version = "1.0.0";
 my %opts =  (
     ABSTRACT      => 'Utilities to view the nis netgroup map',
     AUTHOR        => 'Marc Prewitt <mprewitt@chelsea.net>',
-    NAME          => 'Net',
+    NAME          => 'Net::NIS::Listgroup',
     DISTNAME      => 'Net-NIS-Listgroup',
     VERSION       => $version,
     DEFINE        => '-DMAKEFILE_PL_VER=' . (qw$Revision: 1.12 $)[1],
