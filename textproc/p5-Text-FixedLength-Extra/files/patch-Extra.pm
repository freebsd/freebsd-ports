--- Extra.pm.orig	Sat Dec 30 18:10:06 2000
+++ Extra.pm	Sat Dec 30 18:26:45 2000
@@ -31,6 +31,9 @@
 
 our $debug = 1;
 
+# kill the previous Text::FixedLength::getFixed to avoid
+# the warning of redefinition
+BEGIN { delete $Text::FixedLength::{getFixed}; }
 
 # Preloaded methods go here.
 # ----------------------------------------------------------------------------
