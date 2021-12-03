--- lib/r10k/settings.rb.orig	2021-12-03 17:56:58 UTC
+++ lib/r10k/settings.rb
@@ -189,8 +189,8 @@ module R10K
         }),
 
         Definition.new(:puppet_path, {
-          :desc => "Path to puppet executable. Defaults to /opt/puppetlabs/bin/puppet.",
-          :default => '/opt/puppetlabs/bin/puppet',
+          :desc => "Path to puppet executable. Defaults to %%PREFIX%%/bin/puppet.",
+          :default => '%%PREFIX%%/bin/puppet',
           :validate => lambda do |value|
             unless File.executable? value
               raise ArgumentError, "The specified puppet executable #{value} is not executable"
