--- lib/chef/encrypted_data_bag_item.rb.orig	2014-11-18 04:04:36 UTC
+++ lib/chef/encrypted_data_bag_item.rb
@@ -36,7 +36,7 @@ require 'open-uri'
 # If the shared secret is not specified at initialization or load,
 # then the contents of the file referred to in
 # Chef::Config[:encrypted_data_bag_secret] will be used as the
-# secret.  The default path is /etc/chef/encrypted_data_bag_secret
+# secret.  The default path is %%PREFIX%%/etc/chef/encrypted_data_bag_secret
 #
 # EncryptedDataBagItem is intended to provide a means to avoid storing
 # data bag items in the clear on the Chef server.  This provides some
@@ -127,7 +127,7 @@ class Chef::EncryptedDataBagItem
   def self.load_secret(path=nil)
     path ||= Chef::Config[:encrypted_data_bag_secret]
     if !path
-      raise ArgumentError, "No secret specified to load_secret and no secret found at #{Chef::Config.platform_specific_path('/etc/chef/encrypted_data_bag_secret')}"
+      raise ArgumentError, "No secret specified to load_secret and no secret found at #{Chef::Config.platform_specific_path('%%PREFIX%%/etc/chef/encrypted_data_bag_secret')}"
     end
     secret = case path
              when /^\w+:\/\//
