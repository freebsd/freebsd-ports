--- scripts/cli-backend.php.orig	Wed Apr 17 20:00:46 2002
+++ scripts/cli-backend.php	Sat Jun 29 17:04:47 2002
@@ -3,7 +3,7 @@
 // $Horde: jonah/scripts/cli-backend.php,v 1.5 2002/04/17 18:00:46 jan Exp $
 
 $self_contained_auth = true;
-define('JONAH_BASE', dirname(__FILE__) . '/..');
+define('JONAH_BASE', %%JONAHDIR%%);
 
 // This shouldn't be callable via the web.
 if (isset($_SERVER['SCRIPT_NAME']) ||
