--- ./Build.PL.orig	2013-01-16 16:08:24.583714613 +0800
+++ ./Build.PL	2013-01-16 16:09:30.191293173 +0800
@@ -1,3 +1,5 @@
+use Module::Build;
+
 my $have_apache_test = 0;
 my $build_pkg = 'Module::Build';
 eval "require Apache::Test";
