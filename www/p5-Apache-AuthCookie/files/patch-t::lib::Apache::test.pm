--- t/lib/Apache/test.pm.orig	Sun Mar 25 20:35:03 2001
+++ t/lib/Apache/test.pm	Fri Jun  6 05:14:49 2003
@@ -102,6 +102,7 @@
 
 sub get_test_params {
     my $pkg = shift;
+return;
 
     print("\nFor testing purposes, please give the full path to an httpd\n",
 	  "with mod_perl enabled.  The path defaults to \$ENV{APACHE}, if present.");
