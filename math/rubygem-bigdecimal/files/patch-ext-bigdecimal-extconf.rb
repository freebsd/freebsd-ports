--- ext/bigdecimal/extconf.rb.orig	2020-08-21 18:03:52 UTC
+++ ext/bigdecimal/extconf.rb
@@ -6,7 +6,7 @@ def check_bigdecimal_version(gemspec_path)
 
   bigdecimal_version =
     IO.readlines(gemspec_path)
-      .grep(/\Abigdecimal_version\s+=\s+/)[0][/\'([^\']+)\'/, 1]
+      .grep(/\s+s.version\s+=\s+/)[0][/\"([^\']+)\"/, 1]
 
   version_components = bigdecimal_version.split('.')
   bigdecimal_version = version_components[0, 3].join('.')
