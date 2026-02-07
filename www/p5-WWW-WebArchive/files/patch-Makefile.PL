--- Makefile.PL.orig	2006-08-19 13:56:38 UTC
+++ Makefile.PL
@@ -12,7 +12,7 @@ my @programs = (
 );
 
 %opts = (
-    'NAME'         => 'WWW-WebArchive',
+    'NAME'         => 'WWW::WebArchive',
     'DISTNAME'     => 'WWW-WebArchive',
     'VERSION_FROM' => 'lib/WWW/WebArchive.pm',
     'EXE_FILES'    => [ @programs ],
