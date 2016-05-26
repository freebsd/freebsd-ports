--- lib/chef/application/client.rb.orig	2014-11-18 04:04:36 UTC
+++ lib/chef/application/client.rb
@@ -279,7 +279,7 @@ class Chef::Application::Client < Chef::
         require 'chef/knife'
         config[:config_file] = Chef::Knife.locate_config_file
       else
-        config[:config_file] = Chef::Config.platform_specific_path("/etc/chef/client.rb")
+        config[:config_file] = Chef::Config.platform_specific_path("%%PREFIX%%/etc/chef/client.rb")
       end
     end
     super
