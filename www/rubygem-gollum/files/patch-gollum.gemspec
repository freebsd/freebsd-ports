--- gollum.gemspec.orig	2017-03-12 10:42:22 UTC
+++ gollum.gemspec
@@ -27,10 +27,10 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<gollum-lib>.freeze, [">= 4.0.1", "~> 4.0"])
-      s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 1.8.0"])
+      s.add_runtime_dependency(%q<kramdown>.freeze, [">= 1.8.0"])
       s.add_runtime_dependency(%q<sinatra>.freeze, [">= 1.4.4", "~> 1.4"])
       s.add_runtime_dependency(%q<mustache>.freeze, ["< 1.0.0", ">= 0.99.5"])
-      s.add_runtime_dependency(%q<useragent>.freeze, ["~> 0.14.0"])
+      s.add_runtime_dependency(%q<useragent>.freeze, [">= 0.14.0"])
       s.add_development_dependency(%q<rack-test>.freeze, ["~> 0.6.2"])
       s.add_development_dependency(%q<shoulda>.freeze, ["~> 3.5.0"])
       s.add_development_dependency(%q<minitest-reporters>.freeze, ["~> 0.14.16"])
@@ -39,10 +39,10 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
     else
       s.add_dependency(%q<gollum-lib>.freeze, [">= 4.0.1", "~> 4.0"])
-      s.add_dependency(%q<kramdown>.freeze, ["~> 1.8.0"])
+      s.add_dependency(%q<kramdown>.freeze, [">= 1.8.0"])
       s.add_dependency(%q<sinatra>.freeze, [">= 1.4.4", "~> 1.4"])
       s.add_dependency(%q<mustache>.freeze, ["< 1.0.0", ">= 0.99.5"])
-      s.add_dependency(%q<useragent>.freeze, ["~> 0.14.0"])
+      s.add_dependency(%q<useragent>.freeze, [">= 0.14.0"])
       s.add_dependency(%q<rack-test>.freeze, ["~> 0.6.2"])
       s.add_dependency(%q<shoulda>.freeze, ["~> 3.5.0"])
       s.add_dependency(%q<minitest-reporters>.freeze, ["~> 0.14.16"])
@@ -52,10 +52,10 @@ Gem::Specification.new do |s|
     end
   else
     s.add_dependency(%q<gollum-lib>.freeze, [">= 4.0.1", "~> 4.0"])
-    s.add_dependency(%q<kramdown>.freeze, ["~> 1.8.0"])
+    s.add_dependency(%q<kramdown>.freeze, [">= 1.8.0"])
     s.add_dependency(%q<sinatra>.freeze, [">= 1.4.4", "~> 1.4"])
     s.add_dependency(%q<mustache>.freeze, ["< 1.0.0", ">= 0.99.5"])
-    s.add_dependency(%q<useragent>.freeze, ["~> 0.14.0"])
+    s.add_dependency(%q<useragent>.freeze, [">= 0.14.0"])
     s.add_dependency(%q<rack-test>.freeze, ["~> 0.6.2"])
     s.add_dependency(%q<shoulda>.freeze, ["~> 3.5.0"])
     s.add_dependency(%q<minitest-reporters>.freeze, ["~> 0.14.16"])
