--- Makefile.PL.orig	Fri Jan 31 20:36:41 2003
+++ Makefile.PL	Sat Feb  1 13:07:44 2003
@@ -1,13 +1,13 @@
 use strict;
 use ExtUtils::MakeMaker;
-use lib 't/lib';  # distributed here until changes are incorporated into the real version
+#use lib 't/lib';  # distributed here until changes are incorporated into the real version
 use Apache::test qw(have_httpd);
 
-my %params = Apache::test->get_test_params();
-Apache::test->write_httpd_conf
-    (%params,
-     include => do {local $/; open FH, 't/config.incl'; <FH>});
-*MY::test = sub { Apache::test->MM_test(%params) } if have_httpd();
+#my %params = Apache::test->get_test_params();
+#Apache::test->write_httpd_conf
+#    (%params,
+#     include => do {local $/; open FH, 't/config.incl'; <FH>});
+#*MY::test = sub { Apache::test->MM_test(%params) } if have_httpd();
 
 my $module = 'Apache::Filter';
 my ($name, $dir);
@@ -27,7 +27,4 @@
              },
    'PL_FILES' => {},
    'clean' => {FILES => "t/httpd t/httpd.conf t/error_log"},
-   'PREREQ_PM' => {
-                   'mod_perl' => '1.24_01',
-		  },
   );
