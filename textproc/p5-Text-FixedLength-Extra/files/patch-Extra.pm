--- Extra.pm.orig	2001-09-18 13:10:20 UTC
+++ Extra.pm
@@ -31,6 +31,9 @@ our $VERSION = '1.1';
 
 our $debug = 0;
 
+# kill the previous Text::FixedLength::getFixed to avoid
+# the warning of redefinition
+BEGIN { delete $Text::FixedLength::{getFixed}; }
 
 # Preloaded methods go here.
 # ----------------------------------------------------------------------------
