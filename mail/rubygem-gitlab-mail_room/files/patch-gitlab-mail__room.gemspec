--- gitlab-mail_room.gemspec.orig	2022-07-26 08:03:24 UTC
+++ gitlab-mail_room.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<net-imap>.freeze, [">= 0.2.1"])
-    s.add_runtime_dependency(%q<oauth2>.freeze, ["~> 1.4.4"])
+    s.add_runtime_dependency(%q<oauth2>.freeze, ["~> 2.0.0"])
     s.add_runtime_dependency(%q<jwt>.freeze, [">= 2.0"])
     s.add_runtime_dependency(%q<io-wait>.freeze, ["~> 0.1.0"])
     s.add_development_dependency(%q<rake>.freeze, [">= 0"])
@@ -43,7 +43,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<webmock>.freeze, [">= 0"])
   else
     s.add_dependency(%q<net-imap>.freeze, [">= 0.2.1"])
-    s.add_dependency(%q<oauth2>.freeze, ["~> 1.4.4"])
+    s.add_dependency(%q<oauth2>.freeze, ["~> 2.0.0"])
     s.add_dependency(%q<jwt>.freeze, [">= 2.0"])
     s.add_dependency(%q<io-wait>.freeze, ["~> 0.1.0"])
     s.add_dependency(%q<rake>.freeze, [">= 0"])
