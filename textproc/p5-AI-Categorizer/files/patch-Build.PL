--- Build.PL.orig	2007-03-24 03:31:23.000000000 +0100
+++ Build.PL	2011-11-01 22:57:36.305936002 +0100
@@ -28,20 +28,5 @@ my $build = new Module::Build
    create_makefile_pl => 'passthrough',
   );
 
-my $categorizer = File::Spec->catfile('eg', 'categorizer');
-if ($build->y_n("Do you want to install the $categorizer script to $Config{installscript}?", 'n')) {
-  $build->scripts($categorizer);
-}
-
-
 $build->create_build_script;
 
-{
-  my $path = $build->prompt
-    (
-     "\nIf you have the Weka system installed, please specify the path\n".
-     "to the 'weka.jar' file, or '-' to search CLASSPATH, or '!' to skip:",
-     '!'
-    );
-  $build->notes(classpath => $path eq '!' ? undef : $path);
-}
