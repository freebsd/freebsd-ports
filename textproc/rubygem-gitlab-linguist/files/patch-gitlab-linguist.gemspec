--- gitlab-linguist.gemspec.orig	2015-05-22 21:29:46 UTC
+++ gitlab-linguist.gemspec
@@ -20,8 +20,8 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<charlock_holmes>, ["~> 0.6.6"])
-      s.add_runtime_dependency(%q<escape_utils>, ["~> 0.2.4"])
+      s.add_runtime_dependency(%q<charlock_holmes>, [">= 0.6.6"])
+      s.add_runtime_dependency(%q<escape_utils>, [">= 0.2.4"])
       s.add_runtime_dependency(%q<mime-types>, ["~> 1.19"])
       s.add_development_dependency(%q<mocha>, [">= 0"])
       s.add_development_dependency(%q<json>, [">= 0"])
