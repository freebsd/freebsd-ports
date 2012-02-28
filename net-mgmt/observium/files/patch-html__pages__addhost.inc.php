--- html/pages/addhost.inc.php.orig	2011-09-08 09:10:31.000000000 -0800
+++ html/pages/addhost.inc.php	2012-02-20 07:26:57.000000000 -0900
@@ -13,7 +13,11 @@
   if ($_SESSION['userlevel'] > '5')
   {
     $hostname = mres($_POST['hostname']);
-    if ($_POST['community']) { $community = mres($_POST['community']); } else { $community = $config['snmp']['community']; }
+    if ($_POST['community'])
+    {
+	    $community = mres($_POST['community']);
+	    array_unshift($config['snmp']['community'], $community);
+    } else { $community = $config['snmp']['community'][0]; }
     $snmpver = mres($_POST['snmpver']);
     if ($_POST['port']) { $port = mres($_POST['port']); } else { $port = "161"; }
     print_message("Adding host $hostname community $community port $port");
