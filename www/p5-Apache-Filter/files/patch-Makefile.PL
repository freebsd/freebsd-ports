--- Makefile.PL.orig	Mon Apr  2 16:06:30 2001
+++ Makefile.PL	Mon Apr  2 16:06:59 2001
@@ -1,13 +1,4 @@
 use ExtUtils::MakeMaker;
-use lib 't/lib';  # distributed here until changes are incorporated into the real version
-use Apache::test;
-
-my %params = Apache::test->get_test_params();
-chomp (my $cwd = `pwd`);
-Apache::test->write_httpd_conf
-    (%params,
-     include => do {local $/; <DATA>});
-*MY::test = sub { Apache::test->MM_test(%params) };
 
 my $module = 'Apache::Filter';
 my ($name, $dir);
