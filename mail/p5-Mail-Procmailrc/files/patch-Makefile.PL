--- Makefile.PL.orig	Wed Jan 22 15:53:59 2003
+++ Makefile.PL	Wed Jan 22 15:54:17 2003
@@ -3,7 +3,7 @@
 # the contents of the Makefile that is written.
 WriteMakefile(
     'NAME'		=> 'Mail::Procmailrc',
-    'VERSION_FROM'	=> 'Procmailrc.pm', # finds $VERSION
+    'VERSION'		=> '1.03',
     'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
     ($] >= 5.005 ?    ## Add these new keywords supported since 5.005
       (ABSTRACT_FROM => 'Procmailrc.pm', # retrieve abstract from module
