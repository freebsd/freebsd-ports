--- Makefile.PL	Sat Oct 23 15:26:40 2004
+++ Makefile.PL	Sat Oct 23 15:27:02 2004
@@ -4,10 +4,12 @@
 use Config qw(%Config);
 use ExtUtils::MakeMaker;
 
+eval { require Apache2 };
+
 WriteMakefile 
   (
    'NAME'         => 'Apache::AuthenCache',
    'VERSION_FROM' => 'AuthenCache.pm',
-   'PREREQ_PM'    => { 'Apache' => '1.26', 'Cache::Cache' => '1.01' },
+   'PREREQ_PM'    => { 'mod_perl' => '1.26', 'Cache::Cache' => '1.01', 'Time::Object' => '0' },
    'dist'         => { 'COMPRESS' => 'gzip -9f', 'SUFFIX' => 'gz', },
   );
