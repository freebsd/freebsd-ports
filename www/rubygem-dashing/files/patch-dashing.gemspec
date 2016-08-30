--- dashing.gemspec.orig	2016-08-24 17:52:31 UTC
+++ dashing.gemspec
@@ -23,14 +23,14 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<sass>.freeze, ["~> 3.2.12"])
-      s.add_runtime_dependency(%q<coffee-script>.freeze, ["~> 2.2.0"])
-      s.add_runtime_dependency(%q<execjs>.freeze, ["~> 2.0.2"])
+      s.add_runtime_dependency(%q<coffee-script>.freeze, [">= 2.2.0"])
+      s.add_runtime_dependency(%q<execjs>.freeze, [">= 2.0.2"])
       s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4.4"])
       s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 1.4.2"])
       s.add_runtime_dependency(%q<thin>.freeze, ["~> 1.6.1"])
-      s.add_runtime_dependency(%q<rufus-scheduler>.freeze, ["~> 2.0.24"])
+      s.add_runtime_dependency(%q<rufus-scheduler>.freeze, [">= 2.0.24"])
       s.add_runtime_dependency(%q<thor>.freeze, ["> 0.18.1"])
-      s.add_runtime_dependency(%q<sprockets>.freeze, ["~> 2.10.1"])
+      s.add_runtime_dependency(%q<sprockets>.freeze, [">= 2.10.1"])
       s.add_runtime_dependency(%q<rack>.freeze, ["~> 1.5.4"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.1.0"])
       s.add_development_dependency(%q<haml>.freeze, ["~> 4.0.4"])
