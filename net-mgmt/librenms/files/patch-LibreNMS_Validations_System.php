--- LibreNMS/Validations/System.php.orig	2023-08-21 20:59:01 UTC
+++ LibreNMS/Validations/System.php
@@ -40,19 +40,12 @@ class System extends BaseValidation
     {
         $install_dir = $validator->getBaseDir();
 
-        $lnms = str_replace('lnms:', '', rtrim(`whereis -b lnms 2>/dev/null`));
+        $lnms = rtrim(`/usr/bin/find %%LOCALBASE%%/bin -name lnms`);
         $path = rtrim(`echo "\$PATH"`);
 
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
