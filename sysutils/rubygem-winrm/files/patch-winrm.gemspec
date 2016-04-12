--- winrm.gemspec.orig	2016-03-31 14:32:02 UTC
+++ winrm.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<gssapi>.freeze, ["~> 1.2"])
       s.add_runtime_dependency(%q<httpclient>.freeze, [">= 2.2.0.2", "~> 2.2"])
-      s.add_runtime_dependency(%q<rubyntlm>.freeze, ["~> 0.4.0"])
+      s.add_runtime_dependency(%q<rubyntlm>.freeze, [">= 0.4.0"])
       s.add_runtime_dependency(%q<uuidtools>.freeze, ["~> 2.1.2"])
       s.add_runtime_dependency(%q<logging>.freeze, [">= 1.6.1", "~> 1.6"])
       s.add_runtime_dependency(%q<nori>.freeze, ["~> 2.0"])
