--- hiera-eyaml.gemspec.orig	2017-07-08 00:14:31 UTC
+++ hiera-eyaml.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<trollop>.freeze, ["~> 2.0"])
-      s.add_runtime_dependency(%q<highline>.freeze, ["~> 1.6.19"])
+      s.add_runtime_dependency(%q<highline>.freeze, ["~> 1.6"])
     else
       s.add_dependency(%q<trollop>.freeze, ["~> 2.0"])
       s.add_dependency(%q<highline>.freeze, ["~> 1.6.19"])
