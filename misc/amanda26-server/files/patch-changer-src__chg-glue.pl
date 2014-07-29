--- changer-src/chg-glue.pl.orig	2009-01-28 15:06:00.000000000 +0900
+++ changer-src/chg-glue.pl	2009-01-28 15:06:22.000000000 +0900
@@ -206,6 +206,7 @@
 	finish();
 	return;
     }
+    chomp($command);
 
     if (($slot) = ($command =~ /^-slot (.*)$/)) {
 	do_slot($slot);
