--- LibreNMS/Util/FileLock.php.orig	2018-01-14 15:32:35 UTC
+++ LibreNMS/Util/FileLock.php
@@ -45,7 +45,7 @@ class FileLock implements Lock
         global $config;
 
         $this->name = $lock_name;
-        $this->file = "$config[install_dir]/.$lock_name.lock";
+        $this->file = "/tmp/.$lock_name.lock";
         $this->handle = fopen($this->file, "w+");
     }
 
