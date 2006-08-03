--- Build.PL.orig	Thu Aug  3 12:51:01 2006
+++ Build.PL	Thu Aug  3 12:51:20 2006
@@ -5,8 +5,8 @@
   (
    module_name => 'Algorithm::SVMLight',
    license => 'perl',
-   extra_linker_flags => '-lsvmlight',
-   extra_compiler_flags => '-Wall',
+   extra_linker_flags => '-L%%LOCALBASE%%/lib -lsvmlight',
+   extra_compiler_flags => '-I%%LOCALBASE%%/include/svmlight -Wall',
    create_makefile_pl => 'passthrough',
    build_requires => {
 		      'Module::Build' => '0.21',
