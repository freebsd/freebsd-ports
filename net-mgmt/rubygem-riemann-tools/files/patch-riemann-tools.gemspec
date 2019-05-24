--- riemann-tools.gemspec.orig	2018-12-12 11:20:36 UTC
+++ riemann-tools.gemspec
@@ -26,16 +26,16 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<riemann-client>.freeze, ["~> 0.2", ">= 0.2.6"])
       s.add_runtime_dependency(%q<optimist>.freeze, ["~> 3.0", ">= 3.0.0"])
-      s.add_runtime_dependency(%q<json>.freeze, ["~> 1.8"])
+      s.add_runtime_dependency(%q<json>.freeze, [">= 1.8"])
     else
       s.add_dependency(%q<riemann-client>.freeze, ["~> 0.2", ">= 0.2.6"])
       s.add_dependency(%q<optimist>.freeze, ["~> 3.0", ">= 3.0.0"])
-      s.add_dependency(%q<json>.freeze, ["~> 1.8"])
+      s.add_dependency(%q<json>.freeze, [">= 1.8"])
     end
   else
     s.add_dependency(%q<riemann-client>.freeze, ["~> 0.2", ">= 0.2.6"])
     s.add_dependency(%q<optimist>.freeze, ["~> 3.0", ">= 3.0.0"])
-    s.add_dependency(%q<json>.freeze, ["~> 1.8"])
+    s.add_dependency(%q<json>.freeze, [">= 1.8"])
   end
 end
 
