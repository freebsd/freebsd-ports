--- Build.PL.orig	2007-03-24 03:31:23.000000000 +0100
+++ Build.PL	2008-04-30 14:57:51.000000000 +0200
@@ -36,12 +36,3 @@
 
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
