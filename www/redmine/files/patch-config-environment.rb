--- config/environment.rb.orig	2011-01-28 03:25:48.000000000 +0100
+++ config/environment.rb	2011-02-26 21:20:07.000000000 +0100
@@ -17,6 +17,19 @@
   # Not available
 end
 
+# Workaround for RubyGems 1.5.0
+# http://www.redmine.org/issues/7516
+if Gem::VERSION >= "1.3.6" 
+  module Rails
+    class GemDependency
+      def requirement
+        r = super
+        (r == Gem::Requirement.default) ? nil : r
+      end
+    end
+  end
+end
+
 Rails::Initializer.run do |config|
   # Settings in config/environments/* take precedence those specified here
   
