--- tools/module.pl.orig	Sat Feb 28 15:03:52 2004
+++ tools/module.pl	Sat Feb 28 15:04:06 2004
@@ -419,7 +419,7 @@
 
 
 sub lock_mod {
-    my $lock = "$BigSister::common::fs{'var'}/module.lock";
+    my $lock = "$BigSister::common::fs{'tmp'}/module.lock";
     my $locktmp = "$lock.$$";
     push( @tmp, $locktmp );
     my $timeout = time + 5;
