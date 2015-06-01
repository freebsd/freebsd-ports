--- gollum-lib.gemspec.orig	2015-05-22 13:15:19 UTC
+++ gollum-lib.gemspec
@@ -26,10 +26,10 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<gollum-grit_adapter>, ["~> 1.0"])
-      s.add_runtime_dependency(%q<rouge>, ["~> 1.7.4"])
+      s.add_runtime_dependency(%q<rouge>, [">= 1.7.4"])
       s.add_runtime_dependency(%q<nokogiri>, ["~> 1.6.4"])
       s.add_runtime_dependency(%q<stringex>, ["~> 2.5.1"])
-      s.add_runtime_dependency(%q<sanitize>, ["~> 2.1.0"])
+      s.add_runtime_dependency(%q<sanitize>, [">= 2.1.0"])
       s.add_runtime_dependency(%q<github-markup>, ["~> 1.3.3"])
       s.add_development_dependency(%q<org-ruby>, ["~> 0.9.9"])
       s.add_development_dependency(%q<kramdown>, ["~> 1.6.0"])
