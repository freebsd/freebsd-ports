--- Makefile.PL.orig	Thu Jul 25 10:12:25 2002
+++ Makefile.PL	Thu Jul 25 10:12:25 2002
@@ -3,6 +3,6 @@
 # the contents of the Makefile that is written.
 WriteMakefile(
     'NAME'		=> 'Mail::RBL',
-    'VERSION_FROM'	=> 'RBL.pm', # finds $VERSION
+    'VERSION'		=> '1.00',
     'PREREQ_PM'		=> {}, # e.g., Module::Name => 1.1
 );
