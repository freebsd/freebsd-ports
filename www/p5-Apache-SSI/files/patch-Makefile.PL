--- Makefile.PL.orig	Sat May 26 17:38:41 2001
+++ Makefile.PL	Sat May 26 17:39:28 2001
@@ -1,13 +1,13 @@
 use ExtUtils::MakeMaker;
-use lib 't/lib';
-use Apache::test;
+#use lib 't/lib';
+#use Apache::test;
 
-my %params = Apache::test->get_test_params();
-chomp (my $cwd = `pwd`);
-Apache::test->write_httpd_conf
-    (%params, 
-     include => join '', <DATA>);
-*MY::test = sub { Apache::test->MM_test(%params) };
+#my %params = Apache::test->get_test_params();
+#chomp (my $cwd = `pwd`);
+#Apache::test->write_httpd_conf
+#    (%params, 
+#     include => join '', <DATA>);
+#*MY::test = sub { Apache::test->MM_test(%params) };
 
 
 my $module = 'Apache::SSI';
