--- endpoints/lib/config.php.orig	2025-04-26 04:11:44 UTC
+++ endpoints/lib/config.php
@@ -143,6 +143,7 @@ class phpVBoxConfigClass {
     // added vars to satisfy PHP 8.2+ dynamic property deprecation
     var $enableAdvancedConfig;
     var $enableHDFlushConfig;
+    var $authMaster = false;
 
     /**
 	 * Read user configuration, apply defaults, and do some sanity checking
