--- LibreNMS/Util/Version.php.orig	2023-01-24 21:18:47 UTC
+++ LibreNMS/Util/Version.php
@@ -56,7 +56,7 @@ class Version

     public function date(string $format = 'c'): string
     {
-        return date($format, $this->git->commitDate() ?: filemtime(__FILE__));  // approximate date for non-git installs
+        return date($format, %%RELEASE_TIMESTAMP%%);  // obtained via git show --pretty='%H|%ct' -s %%PORTVERSION%%
     }

     public function name(): string
