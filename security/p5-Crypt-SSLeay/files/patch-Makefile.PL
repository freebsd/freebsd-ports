--- Makefile.PL.orig	2007-07-16 19:19:15.000000000 +0200
+++ Makefile.PL	2007-07-16 19:20:09.000000000 +0200
@@ -271,9 +271,7 @@
 these tests may fail (through no fault of the code).
 
 INFO
-    my $network_tests = prompt
-        "Do you want to run the live tests (y/N) ?",
-        'N';
+    my $network_tests = 'N';
     print OUT "network_tests ", ($network_tests =~ /y/i) ? 1 : 0, "\n";
     close OUT;
 }
