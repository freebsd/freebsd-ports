--- gollum.gemspec.orig	2017-03-16 10:32:51 UTC
+++ gollum.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<gollum-lib>.freeze, [">= 4.0.1", "~> 4.0"])
-      s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 1.9.0"])
+      s.add_runtime_dependency(%q<kramdown>.freeze, [">= 1.9.0"])
       s.add_runtime_dependency(%q<sinatra>.freeze, [">= 1.4.4", "~> 1.4"])
       s.add_runtime_dependency(%q<mustache>.freeze, ["< 1.0.0", ">= 0.99.5"])
       s.add_runtime_dependency(%q<useragent>.freeze, ["~> 0.16.2"])
@@ -41,7 +41,7 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
     else
       s.add_dependency(%q<gollum-lib>.freeze, [">= 4.0.1", "~> 4.0"])
-      s.add_dependency(%q<kramdown>.freeze, ["~> 1.9.0"])
+      s.add_dependency(%q<kramdown>.freeze, [">= 1.9.0"])
       s.add_dependency(%q<sinatra>.freeze, [">= 1.4.4", "~> 1.4"])
       s.add_dependency(%q<mustache>.freeze, ["< 1.0.0", ">= 0.99.5"])
       s.add_dependency(%q<useragent>.freeze, ["~> 0.16.2"])
@@ -56,7 +56,7 @@ Gem::Specification.new do |s|
     end
   else
     s.add_dependency(%q<gollum-lib>.freeze, [">= 4.0.1", "~> 4.0"])
-    s.add_dependency(%q<kramdown>.freeze, ["~> 1.9.0"])
+    s.add_dependency(%q<kramdown>.freeze, [">= 1.9.0"])
     s.add_dependency(%q<sinatra>.freeze, [">= 1.4.4", "~> 1.4"])
     s.add_dependency(%q<mustache>.freeze, ["< 1.0.0", ">= 0.99.5"])
     s.add_dependency(%q<useragent>.freeze, ["~> 0.16.2"])
