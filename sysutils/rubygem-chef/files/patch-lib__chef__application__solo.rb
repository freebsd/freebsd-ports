--- lib/chef/application/solo.rb.orig	2014-11-18 04:04:36 UTC
+++ lib/chef/application/solo.rb
@@ -31,7 +31,7 @@ class Chef::Application::Solo < Chef::Ap
   option :config_file,
     :short => "-c CONFIG",
     :long  => "--config CONFIG",
-    :default => Chef::Config.platform_specific_path('/etc/chef/solo.rb'),
+    :default => Chef::Config.platform_specific_path('%%PREFIX%%/etc/chef/solo.rb'),
     :description => "The configuration file to use"
 
   option :formatter,
