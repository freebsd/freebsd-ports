--- lib/r10k/settings.rb.orig
+++ lib/r10k/settings.rb
@@ -123,8 +123,8 @@
         }),
 
         Definition.new(:puppet_path, {
-          :desc => "Path to puppet executable. Defaults to /opt/puppetlabs/bin/puppet.",
-          :default => '/opt/puppetlabs/bin/puppet',
+          :desc => "Path to puppet executable. Defaults to %%PREFIX%%/bin/puppet.",
+          :default => '%%PREFIX%%/bin/puppet',
           :validate => lambda do |value|
             unless File.executable? value
               raise ArgumentError, "The specified puppet executable #{value} is not executable"
