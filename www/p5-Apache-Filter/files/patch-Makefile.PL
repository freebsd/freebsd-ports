--- Makefile.PL.orig	Sun Apr  8 15:24:25 2001
+++ Makefile.PL	Sat May 26 15:36:16 2001
@@ -1,14 +1,14 @@
 use strict;
 use ExtUtils::MakeMaker;
-use lib 't/lib';  # distributed here until changes are incorporated into the real version
+# use lib 't/lib';  # distributed here until changes are incorporated into the real version
 use Apache::test qw(have_httpd);
-
-my %params = Apache::test->get_test_params();
-chomp (my $cwd = `pwd`);
-Apache::test->write_httpd_conf
-    (%params,
-     include => do {local $/; <DATA>});
-*MY::test = sub { Apache::test->MM_test(%params) } if have_httpd();
+# 
+# my %params = Apache::test->get_test_params();
+# chomp (my $cwd = `pwd`);
+# Apache::test->write_httpd_conf
+#     (%params,
+#      include => do {local $/; <DATA>});
+# *MY::test = sub { Apache::test->MM_test(%params) } if have_httpd();
 
 my $module = 'Apache::Filter';
 my ($name, $dir);
@@ -28,9 +28,6 @@
                       ),
              },
    'clean' => {FILES => "t/httpd t/httpd.conf t/error_log"},
-   'PREREQ_PM' => {
-                   have_httpd() ? ('mod_perl' => '1.24_01') : (),
-		  },
   );
 
 ##################################################################
