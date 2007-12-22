--- Makefile.PL.orig	Sat Dec 22 13:35:43 2007
+++ Makefile.PL	Sat Dec 22 13:35:56 2007
@@ -26,8 +26,6 @@
  , clean        => { FILES => 'test.txt' }
  );
 
-set_test_data();
-
 sub set_test_data {
     unless(-f "lib/Mail/IMAPClient.pm")
     {   warn "ERROR: not in installation directory\n";
