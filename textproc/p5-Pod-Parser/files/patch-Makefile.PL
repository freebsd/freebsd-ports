--- Makefile.PL.orig	Fri Aug 11 01:41:59 2000
+++ Makefile.PL	Thu Sep 12 21:17:34 2002
@@ -4,6 +4,8 @@
 # you can redistribute it and/or modify it under the same terms
 # as Perl itself.
 
+use Config;
+use lib $Config{installsitelib};
 BEGIN {
     require 5.005;
     eval { require File::Spec };
