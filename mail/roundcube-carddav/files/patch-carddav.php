--- carddav.php.orig	2021-11-20 10:58:46 UTC
+++ carddav.php
@@ -1259,6 +1259,9 @@ class carddav extends rcube_plugin
         $logger = Config::inst()->logger();
         $httpLogger = Config::inst()->httpLogger();
         $prefs = [];
+        if (defined('RCUBE_CONFIG_DIR'))
+            $configfile = RCUBE_CONFIG_DIR . "/carddav.inc.php";
+        else
         $configfile = dirname(__FILE__) . "/config.inc.php";
         if (file_exists($configfile)) {
             include($configfile);
