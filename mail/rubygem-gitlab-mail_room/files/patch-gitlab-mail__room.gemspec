--- gitlab-mail_room.gemspec.orig	2023-01-05 21:41:46 UTC
+++ gitlab-mail_room.gemspec
@@ -21,7 +21,7 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<net-imap>.freeze, [">= 0.2.1"])
-  s.add_runtime_dependency(%q<oauth2>.freeze, ["~> 1.4.4"])
+  s.add_runtime_dependency(%q<oauth2>.freeze, ["~> 2.0.0"])
   s.add_runtime_dependency(%q<jwt>.freeze, [">= 2.0"])
   s.add_runtime_dependency(%q<io-wait>.freeze, ["~> 0.1.0"])
   s.add_development_dependency(%q<rake>.freeze, [">= 0"])
