--- ./Makefile.PL.orig	2007-12-20 21:29:34.000000000 +0000
+++ ./Makefile.PL	2007-12-20 21:29:46.000000000 +0000
@@ -12,8 +12,6 @@
 requires('Nagios::Plugin');
 requires('Time::HiRes');
 
-install_script "bin/check_memcached";
-
 use_test_base;
 
 auto_include;
