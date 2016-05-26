--- lib/chef/config.rb.orig	2014-11-18 04:04:36 UTC
+++ lib/chef/config.rb
@@ -413,7 +413,7 @@ class Chef
     # `node_name` of the client.
     #
     # If chef-zero is enabled, this defaults to nil (no authentication).
-    default(:client_key) { chef_zero.enabled ? nil : platform_specific_path("/etc/chef/client.pem") }
+    default(:client_key) { chef_zero.enabled ? nil : platform_specific_path("%%PREFIX%%/etc/chef/client.pem") }
 
     # This secret is used to decrypt encrypted data bag items.
     default(:encrypted_data_bag_secret) do
@@ -421,8 +421,8 @@ class Chef
       # since +Chef::Config[:encrypted_data_bag_secret]+ is read by older
       # bootstrap templates to determine if the local secret should be uploaded to
       # node being bootstrapped. This should be removed in Chef 12.
-      if File.exist?(platform_specific_path("/etc/chef/encrypted_data_bag_secret"))
-        platform_specific_path("/etc/chef/encrypted_data_bag_secret")
+      if File.exist?(platform_specific_path("%%PREFIX%%/etc/chef/encrypted_data_bag_secret"))
+        platform_specific_path("%%PREFIX%%/etc/chef/encrypted_data_bag_secret")
       else
         nil
       end
@@ -451,7 +451,7 @@ class Chef
     # The `validation_key` is never used if the `client_key` exists.
     #
     # If chef-zero is enabled, this defaults to nil (no authentication).
-    default(:validation_key) { chef_zero.enabled ? nil : platform_specific_path("/etc/chef/validation.pem") }
+    default(:validation_key) { chef_zero.enabled ? nil : platform_specific_path("%%PREFIX%%/etc/chef/validation.pem") }
     default :validation_client_name, "chef-validator"
 
     # When creating a new client via the validation_client account, Chef 11
