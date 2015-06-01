--- rest-client.gemspec.orig	2015-06-01 12:01:42 UTC
+++ rest-client.gemspec
@@ -24,15 +24,18 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<mime-types>, [">= 1.16"])
+      s.add_runtime_dependency(%q<http-cookie>, [">= 1.0.2", "< 2.0"])
       s.add_development_dependency(%q<webmock>, [">= 0.9.1"])
       s.add_development_dependency(%q<rspec>, [">= 0"])
     else
       s.add_dependency(%q<mime-types>, [">= 1.16"])
+      s.add_dependency(%q<http-cookie>, [">= 1.0.2", "< 2.0"])
       s.add_dependency(%q<webmock>, [">= 0.9.1"])
       s.add_dependency(%q<rspec>, [">= 0"])
     end
   else
     s.add_dependency(%q<mime-types>, [">= 1.16"])
+    s.add_dependency(%q<http-cookie>, [">= 1.0.2", "< 2.0"])
     s.add_dependency(%q<webmock>, [">= 0.9.1"])
     s.add_dependency(%q<rspec>, [">= 0"])
   end
