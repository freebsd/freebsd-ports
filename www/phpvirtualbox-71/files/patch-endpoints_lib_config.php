--- endpoints/lib/config.php.orig	2025-03-09 01:02:03 UTC
+++ endpoints/lib/config.php
@@ -151,6 +151,7 @@ class phpVBoxConfigClass {
          */
         var $enableHDFlushConfig;
         
+	var $authMaster = false;
         
 	/**
 	 * Read user configuration, apply defaults, and do some sanity checking
