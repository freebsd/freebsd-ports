--- Build.PL.orig	Wed Aug 30 14:19:10 2006
+++ Build.PL	Wed Aug 30 14:19:44 2006
@@ -23,6 +23,7 @@
     dist_version_from => 'lib/Senna.pm',
     license => 'lgpl',
     c_source => 'src',
+    create_packlist => undef,
     extra_compiler_flags => [ 
         split(/\s+/, $config->{cflags}),
         "-DSENNA_MAJOR_VERSION=$major",
@@ -69,4 +70,4 @@
 EOSUB
 
 my $build = $class->new(%args);
-$build->create_build_script;
\ No newline at end of file
+$build->create_build_script;
