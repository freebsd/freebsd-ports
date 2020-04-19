--- gitlab-gollum-rugged_adapter.gemspec.orig	2020-04-14 05:55:27 UTC
+++ gitlab-gollum-rugged_adapter.gemspec
@@ -21,7 +21,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<rugged>.freeze, ["~> 0.25"])
+      s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<mime-types>.freeze, [">= 1.15"])
       s.add_development_dependency(%q<rspec>.freeze, ["= 3.4.0"])
     else
