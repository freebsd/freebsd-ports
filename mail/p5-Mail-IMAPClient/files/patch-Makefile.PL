--- Makefile.PL.orig	Sat Sep  8 11:45:48 2001
+++ Makefile.PL	Sat Sep  8 11:46:03 2001
@@ -10,8 +10,6 @@
 );
 
 
-&set_test_data;
-
 sub set_test_data {
 	unless (-f "./IMAPClient.pm") { warn "ERROR: not in installation directory\n"; return }
 	return if -f "./test.txt";
