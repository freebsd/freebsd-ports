--- Makefile.PL.orig	Wed May  2 15:21:00 2001
+++ Makefile.PL	Wed May  2 15:21:25 2001
@@ -1,14 +1,14 @@
 use strict;
 use ExtUtils::MakeMaker;
-use lib 't/lib';  # distributed here until changes are incorporated into the real version
-use Apache::test qw(have_httpd);
-
-my %params = Apache::test->get_test_params();
-chomp (my $cwd = `pwd`);
-Apache::test->write_httpd_conf
-    (%params,
-     include => do {local $/; <DATA>});
-*MY::test = sub { Apache::test->MM_test(%params) } if have_httpd();
+# use lib 't/lib';  # distributed here until changes are incorporated into the real version
+# use Apache::test qw(have_httpd);
+# 
+# my %params = Apache::test->get_test_params();
+# chomp (my $cwd = `pwd`);
+# Apache::test->write_httpd_conf
+#     (%params,
+#      include => do {local $/; <DATA>});
+# *MY::test = sub { Apache::test->MM_test(%params) } if have_httpd();
 
 my $module = 'Apache::Filter';
 my ($name, $dir);
