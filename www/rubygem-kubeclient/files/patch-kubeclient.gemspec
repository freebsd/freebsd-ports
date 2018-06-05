--- kubeclient.gemspec.orig	2018-05-02 18:24:40 UTC
+++ kubeclient.gemspec
@@ -32,7 +32,7 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<rubocop>.freeze, ["= 0.49.1"])
       s.add_runtime_dependency(%q<rest-client>.freeze, ["~> 2.0"])
       s.add_runtime_dependency(%q<recursive-open-struct>.freeze, ["~> 1.0.4"])
-      s.add_runtime_dependency(%q<http>.freeze, ["~> 2.2.2"])
+      s.add_runtime_dependency(%q<http>.freeze, [">= 2.2.2"])
     else
       s.add_dependency(%q<bundler>.freeze, ["~> 1.6"])
       s.add_dependency(%q<rake>.freeze, ["~> 12.0"])
