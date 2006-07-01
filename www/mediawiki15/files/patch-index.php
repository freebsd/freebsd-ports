--- config/index.php.orig	Thu Mar  2 03:55:15 2006
+++ config/index.php	Sat Jul  1 13:32:47 2006
@@ -321,7 +321,7 @@
 $diff3locations = array("/usr/bin", "/opt/csw/bin", "/usr/gnu/bin", "/usr/sfw/bin") + explode(":", getenv("PATH"));
 $diff3names = array("gdiff3", "diff3");
 
-$diff3versioninfo = array('$1 --version 2>&1', 'diff3 (GNU diffutils)');
+$diff3versioninfo = array('$1 --version 2>&1', 'diff3 - GNU diffutils');
 foreach ($diff3locations as $loc) {
 	$exe = locate_executable($loc, $diff3names, $diff3versioninfo);
 	if ($exe !== false) {
