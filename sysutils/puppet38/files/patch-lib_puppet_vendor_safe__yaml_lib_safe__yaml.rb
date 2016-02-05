--- lib/puppet/vendor/safe_yaml/lib/safe_yaml.rb.orig	2015-08-06 16:17:42 UTC
+++ lib/puppet/vendor/safe_yaml/lib/safe_yaml.rb
@@ -3,7 +3,7 @@ require "yaml"
 # This needs to be defined up front in case any internal classes need to base
 # their behavior off of this.
 module SafeYAML
-  YAML_ENGINE = defined?(YAML::ENGINE) ? YAML::ENGINE.yamler : "syck"
+  YAML_ENGINE = defined?(YAML::ENGINE) ? YAML::ENGINE.yamler : (defined?(Psych) && YAML == Psych ? "psych" : "syck") 
 end
 
 require "set"
