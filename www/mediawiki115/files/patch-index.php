--- config/index.php.orig	Sat Oct 14 02:06:36 2006
+++ config/index.php	Sun Dec  3 16:18:18 2006
@@ -434,7 +434,7 @@
 $diff3locations = array( "/usr/bin", "/usr/local/bin", "/opt/csw/bin", "/usr/gnu/bin", "/usr/sfw/bin" ) + explode( $sep, getenv( "PATH" ) );
 $diff3names = array( "gdiff3", "diff3", "diff3.exe" );
 
-$diff3versioninfo = array( '$1 --version 2>&1', 'diff3 (GNU diffutils)' );
+$diff3versioninfo = array('$1 --version 2>&1', 'diff3 - GNU diffutils');
 foreach ($diff3locations as $loc) {
 	$exe = locate_executable($loc, $diff3names, $diff3versioninfo);
 	if ($exe !== false) {
