--- Makefile.PL.orig	Thu Sep 23 18:16:48 2004
+++ Makefile.PL	Thu Sep 23 18:17:14 2004
@@ -14,6 +14,9 @@
 *EOF*
     sleep 3;
 
+# Detect PREREQ_PM if they are installed in Apache2/.
+eval { require Apache2 };
+
 WriteMakefile(
     NAME              => 'MasonX::Apache2Handler',
     VERSION_FROM      => 'lib/MasonX/Apache2Handler.pm', # finds $VERSION
