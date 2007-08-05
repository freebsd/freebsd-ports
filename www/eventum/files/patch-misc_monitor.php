
$FreeBSD$

--- misc/monitor.php.orig
+++ misc/monitor.php
@@ -39,17 +39,17 @@
 $required_files = array(
     APP_PATH . 'config/config.php' => array(
         'check_owner'      => true,
-        'owner'            => 'apache',
+        'owner'            => 'www',
         'check_group'      => true,
-        'group'            => 'apache',
+        'group'            => 'www',
         'check_permission' => true,
         'permission'       => 755,
     ),
     APP_PATH . 'config/setup.php' => array(
         'check_owner'      => true,
-        'owner'            => 'apache',
+        'owner'            => 'www',
         'check_group'      => true,
-        'group'            => 'apache',
+        'group'            => 'www',
         'check_permission' => true,
         'permission'       => 750,
         'check_filesize'   => true,
