--- winrm.gemspec.orig	2015-06-14 14:46:24 UTC
+++ winrm.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<gssapi>, ["~> 1.2"])
       s.add_runtime_dependency(%q<httpclient>, [">= 2.2.0.2", "~> 2.2"])
-      s.add_runtime_dependency(%q<rubyntlm>, ["~> 0.4.0"])
+      s.add_runtime_dependency(%q<rubyntlm>, [">= 0.4.0"])
       s.add_runtime_dependency(%q<uuidtools>, ["~> 2.1.2"])
       s.add_runtime_dependency(%q<logging>, [">= 1.6.1", "~> 1.6"])
       s.add_runtime_dependency(%q<nori>, ["~> 2.0"])
