--- heroku.gemspec.orig	2015-05-31 17:15:59 UTC
+++ heroku.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<heroku-api>, ["~> 0.3.17"])
       s.add_runtime_dependency(%q<launchy>, [">= 0.3.2"])
       s.add_runtime_dependency(%q<netrc>, ["~> 0.7.7"])
-      s.add_runtime_dependency(%q<rest-client>, ["~> 1.6.1"])
+      s.add_runtime_dependency(%q<rest-client>, [">= 1.6.1"])
       s.add_runtime_dependency(%q<rubyzip>, [">= 0"])
     else
       s.add_dependency(%q<heroku-api>, ["~> 0.3.17"])
