--- Build.PL.orig	Mon Aug 29 02:29:40 2005
+++ Build.PL	Mon Aug 29 02:29:50 2005
@@ -26,6 +26,7 @@
     xs_files => {
         'Senna.xs' => 'lib/Senna.xs'
     },
+    create_packlist => undef,
     extra_compiler_flags => $config->{INC},
     extra_linker_flags => $config->{LIBS}
 );
@@ -38,4 +39,4 @@
     }
 EOSUB
 my $build = $class->new(%args);
-$build->create_build_script;
\ No newline at end of file
+$build->create_build_script;
