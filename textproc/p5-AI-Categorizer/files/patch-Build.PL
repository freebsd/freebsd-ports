--- Build.PL	Mon Feb 20 10:02:49 2006
+++ Build.PL	Mon Feb 20 10:03:57 2006
@@ -27,28 +27,4 @@
 		     },
   );
 
-my $categorizer = File::Spec->catfile('eg', 'categorizer');
-if ($build->y_n("Do you want to install the $categorizer script to $Config{installscript}?", 'n')) {
-  $build->scripts($categorizer);
-}
-
-
-{
-  my $path = $build->prompt
-    (
-     "\nIf you have the Weka system installed, please specify the path\n".
-     "to the 'weka.jar' file, or '-' to search CLASSPATH, or '!' to skip:",
-     '!'
-    );
-  
-  if ($path eq '!') {
-    unlink "classpath" if -e "classpath";
-  } else {
-    local *FH;
-    open FH, "> classpath" or die "Can't create classpath: $!";
-    print FH $path;
-    close FH;
-  }
-}
-
 $build->create_build_script;
