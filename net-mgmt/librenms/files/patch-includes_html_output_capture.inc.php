--- includes/html/output/capture.inc.php.orig	2021-05-25 19:32:48 UTC
+++ includes/html/output/capture.inc.php
@@ -31,7 +31,7 @@ $type = $_REQUEST['type'];
 
 switch ($type) {
     case 'poller':
-        $cmd = ['php', \LibreNMS\Config::get('install_dir') . '/poller.php', '-h', $hostname, '-r', '-f', '-d'];
+        $cmd = ['%%LOCALBASE%%/bin/php', \LibreNMS\Config::get('install_dir') . '/poller.php', '-h', $hostname, '-r', '-f', '-d'];
         $filename = "poller-$hostname.txt";
         break;
     case 'snmpwalk':
@@ -42,7 +42,7 @@ switch ($type) {
         $filename = $device['os'] . '-' . $device['hostname'] . '.snmpwalk';
         break;
     case 'discovery':
-        $cmd = ['php', \LibreNMS\Config::get('install_dir') . '/discovery.php', '-h', $hostname, '-d'];
+        $cmd = ['%%LOCALBASE%%/bin/php', \LibreNMS\Config::get('install_dir') . '/discovery.php', '-h', $hostname, '-d'];
         $filename = "discovery-$hostname.txt";
         break;
     default:
