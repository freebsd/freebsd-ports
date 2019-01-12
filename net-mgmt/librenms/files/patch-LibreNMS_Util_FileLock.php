--- LibreNMS/Util/FileLock.php.orig	2018-12-30 14:29:16 UTC
+++ LibreNMS/Util/FileLock.php
@@ -47,6 +47,7 @@ class FileLock implements Lock
 
         $this->name = $lock_name;
         $this->file = "$install_dir/.$lock_name.lock";
+        $this->file = "/tmp/.$lock_name.lock";
         $this->handle = fopen($this->file, "w+");
     }
 
