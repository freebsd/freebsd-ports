--- config/index.php.orig	Tue Jun  6 11:04:04 2006
+++ config/index.php	Sat Jul  1 13:27:04 2006
@@ -340,7 +340,7 @@
 $diff3locations = array("/usr/bin", "/opt/csw/bin", "/usr/gnu/bin", "/usr/sfw/bin") + explode($sep, getenv("PATH"));
 $diff3names = array("gdiff3", "diff3", "diff3.exe");
 
-$diff3versioninfo = array('$1 --version 2>&1', 'diff3 (GNU diffutils)');
+$diff3versioninfo = array('$1 --version 2>&1', 'diff3 - GNU diffutils');
 foreach ($diff3locations as $loc) {
 	$exe = locate_executable($loc, $diff3names, $diff3versioninfo);
 	if ($exe !== false) {
