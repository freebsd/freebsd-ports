--- Makefile.PL.orig	Mon Sep 30 04:33:16 2002
+++ Makefile.PL	Mon Sep 30 04:34:51 2002
@@ -20,7 +20,7 @@ if (exists($Config{'byteorder'}) and def
 	print "Writing endian.h for SHA\n";
     }
     print "Do you want to use the original SHA or the new standard SHA-1?\nEnter 0 for the original or 1 for the new standard. [1]";
-    $resp = <STDIN>;
+    $resp = 1;
     if (defined($resp)) {
 	$resp =~ s/^\s+//;
 	$resp =~ s/\s+$//;
