--- LibreNMS/Validations/System.php.orig	2025-11-17 19:04:56 UTC
+++ LibreNMS/Validations/System.php
@@ -41,19 +41,12 @@ class System extends BaseValidation
     {
         $install_dir = $validator->getBaseDir();
 
-        $lnms = str_replace('lnms:', '', rtrim((string) `whereis -b lnms 2>/dev/null`));
+        $lnms = rtrim(`/usr/bin/find %%LOCALBASE%%/bin -name lnms`);
         $path = rtrim((string) `echo "\$PATH"`);
 
         // if couldn't find lnms and we have PATH
         if (empty($lnms) && ! empty($path)) {
-            $paths = explode(':', $path);
-            $bin = Arr::first(array_intersect([
-                '/usr/local/bin',
-                '/usr/bin',
-                '/bin',
-            ], $paths), null, Arr::last($paths));
-
-            $validator->warn('Global lnms shortcut not installed. lnms command must be run with full path', "sudo ln -s $install_dir/lnms $bin/lnms");
+            $validator->warn('Global lnms shortcut not installed. lnms command must be run with full path', "sudo ln -s $install_dir/lnms %%LOCALBASE%%/bin/lnms");
         }
 
         $bash_completion_dir = '/etc/bash_completion.d/';
