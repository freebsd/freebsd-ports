--- php/hawk.conf.inc.orig	2002-01-11 17:12:30.000000000 -0800
+++ php/hawk.conf.inc	2012-02-05 03:13:12.000000000 -0800
@@ -1,6 +1,6 @@
 <?php
 
-# database info, should match what's in hawk.conf
+# database info, should match what's in daemon.conf
 $dbuser = "";
 $dbpass = "";
 $dbhost = "mysql";
@@ -12,7 +12,14 @@
 $yellowzone = 60 * 60 * 24;
 $redzone = 60 * 60 * 24 * 7;
 
-# networks, should match what's in hawk.conf
+# optional hostname substring to equate to an empty hostname
+#$purple_string = "unused.";
+
+# comment this out or set to 0 to not display if the forward
+# and reverse hostnames match
+$for_rev_check_default = 1;
+ 
+# networks, should match what's in daemon.conf
 #$networks = array (
 #   "Main Network" => "192.168.64.0/22",
 #   "Training Lab" => "192.168.62.0/24",
