--- orchestrator_client.gemspec.orig	2023-03-24 18:18:51 UTC
+++ orchestrator_client.gemspec
@@ -18,7 +18,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<faraday>.freeze, ["~> 1.4"])
-  s.add_runtime_dependency(%q<net-http-persistent>.freeze, ["~> 4.0"])
+  s.add_runtime_dependency(%q<faraday>.freeze, ["~> 2.0"])
+  s.add_runtime_dependency(%q<faraday-net_http_persistent>.freeze, ["~> 2.0"])
 end
 
