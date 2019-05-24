--- riemann-client.gemspec.orig	2018-12-12 11:07:07 UTC
+++ riemann-client.gemspec
@@ -25,20 +25,20 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_development_dependency(%q<bundler>.freeze, [">= 1.3"])
       s.add_development_dependency(%q<bacon>.freeze, [">= 0"])
-      s.add_runtime_dependency(%q<beefcake>.freeze, [">= 0.3.5", "<= 1.0.0"])
+      s.add_runtime_dependency(%q<beefcake>.freeze, [">= 1.2.0"])
       s.add_runtime_dependency(%q<trollop>.freeze, [">= 1.16.2"])
       s.add_runtime_dependency(%q<mtrc>.freeze, [">= 0.0.4"])
     else
       s.add_dependency(%q<bundler>.freeze, [">= 1.3"])
       s.add_dependency(%q<bacon>.freeze, [">= 0"])
-      s.add_dependency(%q<beefcake>.freeze, [">= 0.3.5", "<= 1.0.0"])
+      s.add_dependency(%q<beefcake>.freeze, [">= 1.2.0"])
       s.add_dependency(%q<trollop>.freeze, [">= 1.16.2"])
       s.add_dependency(%q<mtrc>.freeze, [">= 0.0.4"])
     end
   else
     s.add_dependency(%q<bundler>.freeze, [">= 1.3"])
     s.add_dependency(%q<bacon>.freeze, [">= 0"])
-    s.add_dependency(%q<beefcake>.freeze, [">= 0.3.5", "<= 1.0.0"])
+    s.add_dependency(%q<beefcake>.freeze, [">= 1.2.0"])
     s.add_dependency(%q<trollop>.freeze, [">= 1.16.2"])
     s.add_dependency(%q<mtrc>.freeze, [">= 0.0.4"])
   end
