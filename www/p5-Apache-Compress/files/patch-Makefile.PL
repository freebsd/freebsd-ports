--- Makefile.PL.orig	Tue Sep  9 20:16:44 2003
+++ Makefile.PL	Tue Sep  9 20:17:08 2003
@@ -2,12 +2,12 @@
 use lib 't/lib';  # distributed here until changes are incorporated into the real version
 use Apache::test;
 
-my %params = Apache::test->get_test_params();
-chomp (my $cwd = `pwd`);
-Apache::test->write_httpd_conf
-    (%params,
-     include => do {local $/; <DATA>});
-*MY::test = sub { Apache::test->MM_test(%params) };
+#my %params = Apache::test->get_test_params();
+#chomp (my $cwd = `pwd`);
+#Apache::test->write_httpd_conf
+#    (%params,
+#     include => do {local $/; <DATA>});
+#*MY::test = sub { Apache::test->MM_test(%params) };
 
 my $module = 'Apache::Compress';
 my ($name, $dir);
