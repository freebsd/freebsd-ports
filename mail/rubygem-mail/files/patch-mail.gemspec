--- mail.gemspec.orig	2021-11-10 18:38:59 UTC
+++ mail.gemspec
@@ -24,6 +24,7 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
+    s.add_runtime_dependency(%q<net-smtp>.freeze, [">= 0"])
     s.add_runtime_dependency(%q<mini_mime>.freeze, [">= 0.1.1"])
     s.add_development_dependency(%q<bundler>.freeze, [">= 1.0.3"])
     s.add_development_dependency(%q<rake>.freeze, ["> 0.8.7"])
@@ -31,6 +32,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<rdoc>.freeze, [">= 0"])
     s.add_development_dependency(%q<rufo>.freeze, [">= 0"])
   else
+    s.add_dependency(%q<net-smtp>.freeze, [">= 0"])
     s.add_dependency(%q<mini_mime>.freeze, [">= 0.1.1"])
     s.add_dependency(%q<bundler>.freeze, [">= 1.0.3"])
     s.add_dependency(%q<rake>.freeze, ["> 0.8.7"])
