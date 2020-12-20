--- chef-dk.gemspec.orig	2020-12-19 23:37:18 UTC
+++ chef-dk.gemspec
@@ -35,7 +35,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<cookbook-omnifetch>.freeze, ["~> 0.5"])
       s.add_runtime_dependency(%q<diff-lcs>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<paint>.freeze, ["~> 1.0"])
-      s.add_runtime_dependency(%q<license-acceptance>.freeze, ["~> 1.0", ">= 1.0.11"])
+      s.add_runtime_dependency(%q<license-acceptance>.freeze, ["~> 2.0", ">= 1.0.11"])
       s.add_development_dependency(%q<rspec-core>.freeze, ["~> 3.0"])
       s.add_development_dependency(%q<rspec-expectations>.freeze, ["~> 3.0"])
       s.add_development_dependency(%q<rspec-mocks>.freeze, ["~> 3.0"])
