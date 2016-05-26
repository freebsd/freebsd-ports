--- lib/chef/knife/configure.rb.orig	2014-11-18 04:04:36 UTC
+++ lib/chef/knife/configure.rb
@@ -137,13 +137,13 @@ EOH
         if config[:initial]
           @new_client_name        = config[:node_name] || ask_question("Please enter a name for the new user: ", :default => Etc.getlogin)
           @admin_client_name      = config[:admin_client_name] || ask_question("Please enter the existing admin name: ", :default => 'admin')
-          @admin_client_key       = config[:admin_client_key] || ask_question("Please enter the location of the existing admin's private key: ", :default => '/etc/chef-server/admin.pem')
+          @admin_client_key       = config[:admin_client_key] || ask_question("Please enter the location of the existing admin's private key: ", :default => '%%PREFIX%%/etc/chef-server/admin.pem')
           @admin_client_key       = File.expand_path(@admin_client_key)
         else
           @new_client_name        = config[:node_name] || ask_question("Please enter an existing username or clientname for the API: ", :default => Etc.getlogin)
         end
         @validation_client_name = config[:validation_client_name] || ask_question("Please enter the validation clientname: ", :default => 'chef-validator')
-        @validation_key         = config[:validation_key] || ask_question("Please enter the location of the validation key: ", :default => '/etc/chef-server/chef-validator.pem')
+        @validation_key         = config[:validation_key] || ask_question("Please enter the location of the validation key: ", :default => '%%PREFIX%%/etc/chef-server/chef-validator.pem')
         @validation_key         = File.expand_path(@validation_key)
         @chef_repo              = config[:repository] || ask_question("Please enter the path to a chef repository (or leave blank): ")
 
