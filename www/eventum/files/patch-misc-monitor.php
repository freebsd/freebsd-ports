--- misc/monitor.php.orig	Thu Mar 30 21:13:13 2006
+++ misc/monitor.php	Sat Jun 17 14:53:41 2006
@@ -39,17 +39,17 @@
 $required_files = array(
     APP_PATH . 'config.inc.php' => array(
         'check_owner'      => true,
-        'owner'            => 'apache',
+        'owner'            => 'www',
         'check_group'      => true,
-        'group'            => 'apache',
+        'group'            => 'www',
         'check_permission' => true,
         'permission'       => 755,
     ),
     APP_PATH . 'setup.conf.php' => array(
         'check_owner'      => true,
-        'owner'            => 'apache',
+        'owner'            => 'www',
         'check_group'      => true,
-        'group'            => 'apache',
+        'group'            => 'www',
         'check_permission' => true,
         'permission'       => 750,
         'check_filesize'   => true,
@@ -60,4 +60,4 @@
 Monitor::checkDatabase();
 Monitor::checkMailQueue();
 Monitor::checkIRCBot();
-?>
\ No newline at end of file
+?>
