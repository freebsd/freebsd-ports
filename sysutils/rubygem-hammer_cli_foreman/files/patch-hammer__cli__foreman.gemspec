--- hammer_cli_foreman.gemspec.orig	2015-05-31 16:29:25 UTC
+++ hammer_cli_foreman.gemspec
@@ -25,7 +25,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<hammer_cli>, [">= 0.2.0"])
       s.add_runtime_dependency(%q<apipie-bindings>, [">= 0.0.11"])
-      s.add_runtime_dependency(%q<rest-client>, ["< 1.7", ">= 1.6.5"])
+      s.add_runtime_dependency(%q<rest-client>, [">= 1.6.5"])
     else
       s.add_dependency(%q<hammer_cli>, [">= 0.2.0"])
       s.add_dependency(%q<apipie-bindings>, [">= 0.0.11"])
