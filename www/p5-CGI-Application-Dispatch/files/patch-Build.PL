--- Build.PL.orig       2008-06-05 15:39:53.000000000 -0700
+++ Build.PL    2008-06-05 15:40:02.000000000 -0700
@@ -1,3 +1,5 @@
+use Module::Build;
+
 my $build_pkg = eval "require Apache::TestMB" ? 'Apache::TestMB' : 'Module::Build';
 my $build = $build_pkg->new(
     module_name => 'CGI::Application::Dispatch',

