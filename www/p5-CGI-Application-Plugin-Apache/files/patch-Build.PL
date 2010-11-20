--- Build.PL.orig	Thu Jul 22 13:31:04 2010
+++ Build.PL	Thu Jul 22 13:31:21 2010
@@ -29,7 +29,7 @@
             'HTML::GenerateUtil'=> 0,
 	},
     build_requires      => {
-        'Apache::Test',
+        'Apache::Test' => 1,
     },
     create_makefile_pl  => 'passthrough',
     create_readme       => 1,
