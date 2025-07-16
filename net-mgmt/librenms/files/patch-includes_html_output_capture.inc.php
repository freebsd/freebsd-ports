--- includes/html/output/capture.inc.php.orig	2025-07-16 12:40:13 UTC
+++ includes/html/output/capture.inc.php
@@ -33,7 +33,7 @@ switch ($type) {
 
 switch ($type) {
     case 'poller':
-        $cmd = ['php', \App\Facades\LibrenmsConfig::get('install_dir') . '/lnms', 'device:poll', $hostname, '--no-data', '-vv'];
+        $cmd = ['%%LOCALBASE%%/bin/php', \App\Facades\LibrenmsConfig::get('install_dir') . '/lnms', 'device:poll', $hostname, '--no-data', '-vv'];
         $filename = "poller-$hostname.txt";
         break;
     case 'snmpwalk':
@@ -44,7 +44,7 @@ switch ($type) {
         $filename = $device['os'] . '-' . $device['hostname'] . '.snmpwalk';
         break;
     case 'discovery':
-        $cmd = ['php', \App\Facades\LibrenmsConfig::get('install_dir') . '/discovery.php', '-h', $hostname, '-d'];
+        $cmd = ['%%LOCALBASE%%/bin/php', \App\Facades\LibrenmsConfig::get('install_dir') . '/discovery.php', '-h', $hostname, '-d'];
         $filename = "discovery-$hostname.txt";
         break;
     default:
