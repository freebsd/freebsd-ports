--- Makefile.PL.orig	Tue Jul 15 14:46:36 2003
+++ Makefile.PL	Tue Jul 15 14:46:45 2003
@@ -15,7 +15,6 @@ if ($^O eq 'VMS') {
     }
 }
 
-push(@extra, 'INSTALLDIRS'  => 'perl') if $] >= 5.008;
 
 WriteMakefile(
     'NAME'	   => 'Digest::MD5',
