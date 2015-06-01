--- hammer_cli.gemspec.orig	2015-05-31 16:28:03 UTC
+++ hammer_cli.gemspec
@@ -25,17 +25,15 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<clamp>, [">= 0"])
-      s.add_runtime_dependency(%q<rest-client>, ["< 1.7.0"])
+      s.add_runtime_dependency(%q<rest-client>, [">= 0"])
       s.add_runtime_dependency(%q<logging>, ["< 2.0.0"])
       s.add_runtime_dependency(%q<awesome_print>, [">= 0"])
       s.add_runtime_dependency(%q<table_print>, [">= 0"])
-      s.add_runtime_dependency(%q<highline>, ["< 1.7.0"])
+      s.add_runtime_dependency(%q<highline>, [">= 1.7.0"])
       s.add_runtime_dependency(%q<fast_gettext>, [">= 0"])
       s.add_runtime_dependency(%q<locale>, [">= 2.0.6"])
       s.add_runtime_dependency(%q<json>, [">= 0"])
-      s.add_runtime_dependency(%q<rb-readline>, [">= 0"])
-      s.add_runtime_dependency(%q<fastercsv>, [">= 0"])
-      s.add_runtime_dependency(%q<mime-types>, ["~> 1.0"])
+      s.add_runtime_dependency(%q<mime-types>, [">= 1.0"])
       s.add_runtime_dependency(%q<apipie-bindings>, ["~> 0.0.10"])
     else
       s.add_dependency(%q<clamp>, [">= 0"])
