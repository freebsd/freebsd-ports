--- includes/html/output/capture.inc.php.orig	2023-10-27 13:17:37 UTC
+++ includes/html/output/capture.inc.php
@@ -32,7 +32,7 @@ $type = $_REQUEST['type'];
 
 switch ($type) {
     case 'poller':
-        $cmd = ['php', \LibreNMS\Config::get('install_dir') . '/lnms', 'device:poll', $hostname, '--no-data', '-vv'];
+        $cmd = ['%%LOCALBASE%%/bin/php', \LibreNMS\Config::get('install_dir') . '/lnms', 'device:poll', $hostname, '--no-data', '-vv'];
         $filename = "poller-$hostname.txt";
         break;
     case 'snmpwalk':
@@ -43,7 +43,7 @@ switch ($type) {
         $filename = $device['os'] . '-' . $device['hostname'] . '.snmpwalk';
         break;
     case 'discovery':
-        $cmd = ['php', \LibreNMS\Config::get('install_dir') . '/discovery.php', '-h', $hostname, '-d'];
+        $cmd = ['%%LOCALBASE%%/bin/php', \LibreNMS\Config::get('install_dir') . '/discovery.php', '-h', $hostname, '-d'];
         $filename = "discovery-$hostname.txt";
         break;
     default:
