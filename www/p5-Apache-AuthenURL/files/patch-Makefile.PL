--- Makefile.PL	Wed Aug 16 11:56:21 2000
+++ Makefile.PL	Sat Oct 23 14:58:56 2004
@@ -6,6 +6,7 @@
 my $missing_modules = 0;
 
 print "Checking for Apache::AuthenCache......";
+eval { require Apache2 };
 eval {
     require Apache::AuthenCache;
 };
