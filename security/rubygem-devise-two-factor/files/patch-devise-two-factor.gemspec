--- devise-two-factor.gemspec.orig	2015-07-06 11:45:00 UTC
+++ devise-two-factor.gemspec
@@ -27,8 +27,8 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<railties>, [">= 0"])
       s.add_runtime_dependency(%q<activesupport>, [">= 0"])
       s.add_runtime_dependency(%q<activemodel>, [">= 0"])
-      s.add_runtime_dependency(%q<attr_encrypted>, ["~> 1.3.2"])
-      s.add_runtime_dependency(%q<devise>, ["< 3.5", ">= 3.2.4"])
+      s.add_runtime_dependency(%q<attr_encrypted>, [">= 1.3.2"])
+      s.add_runtime_dependency(%q<devise>, ["< 3.5.2", ">= 3.2.4"])
       s.add_runtime_dependency(%q<rotp>, ["< 2"])
       s.add_development_dependency(%q<bundler>, ["> 1.0"])
       s.add_development_dependency(%q<rspec>, ["< 3", "> 2"])
