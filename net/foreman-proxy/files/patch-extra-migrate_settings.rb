--- extra/migrate_settings.rb.orig	2014-09-27 19:07:54.618974064 +0200
+++ extra/migrate_settings.rb	2014-09-27 19:08:28.098972710 +0200
@@ -96,7 +96,7 @@
 
 # When running as a script
 if __FILE__ == $0 then
-  orig_file = ARGV[0] || '/etc/foreman-proxy/settings.yml'
+  orig_file = ARGV[0] || '%%PREFIX%%/etc/foreman-proxy/settings.yml'
   data      = YAML.load_file(orig_file)
 
   output,unknown = migrate(data.dup)
