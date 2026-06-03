--- lib/r10k/settings/loader.rb.orig	2025-09-04 00:19:16 UTC
+++ lib/r10k/settings/loader.rb
@@ -8,8 +8,8 @@ module R10K
     #
     # r10k.yaml is checked for in the following locations:
     #   - $PWD/r10k.yaml
-    #   - /etc/puppetlabs/r10k/r10k.yaml
-    #   - /etc/r10k.yaml
+    #   - %%PREFIX%%/etc/r10k/r10k.yaml
+    #   - %%PREFIX%%/etc/r10k.yaml
     class Loader
 
       def self.search(override = nil)
@@ -21,8 +21,8 @@ module R10K
       attr_reader :loadpath
 
       CONFIG_FILE = 'r10k.yaml'
-      DEFAULT_LOCATION = File.join('/etc/puppetlabs/r10k', CONFIG_FILE)
-      OLD_DEFAULT_LOCATION = File.join('/etc', CONFIG_FILE)
+      DEFAULT_LOCATION = File.join('%%PREFIX%%/etc/r10k', CONFIG_FILE)
+      OLD_DEFAULT_LOCATION = File.join('%%PREFIX%%/etc', CONFIG_FILE)
 
       def initialize
         @loadpath = []
