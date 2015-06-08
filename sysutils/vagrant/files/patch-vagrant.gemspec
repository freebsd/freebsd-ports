--- vagrant.gemspec.orig	2014-09-04 23:21:10.000000000 +0200
+++ vagrant.gemspec	2015-01-30 22:24:38.000000000 +0100
@@ -15,11 +15,11 @@
   s.required_rubygems_version = ">= 1.3.6"
   s.rubyforge_project         = "vagrant"
 
-  s.add_dependency "bundler", ">= 1.5.2", "< 1.7.0"
+  s.add_dependency "bundler", ">= 1.5.2", "< 1.8.0"
   s.add_dependency "childprocess", "~> 0.5.0"
   s.add_dependency "erubis", "~> 2.7.0"
-  s.add_dependency "i18n", "~> 0.6.0"
-  s.add_dependency "listen", "~> 2.7.1"
+  s.add_dependency "i18n", "~> 0.7.0"
+  s.add_dependency "listen", ">= 2.7.1"
   s.add_dependency "hashicorp-checkpoint", "~> 0.1.1"
   s.add_dependency "log4r", "~> 1.1.9", "< 1.1.11"
   s.add_dependency "net-ssh", ">= 2.6.6", "< 2.10.0"
@@ -29,7 +29,7 @@
   s.add_dependency "winrm", "~> 1.1.3"
 
   # We lock this down to avoid compilation issues.
-  s.add_dependency "nokogiri", "= 1.6.3.1"
+  s.add_dependency "nokogiri", ">= 1.6.3.1"
 
   s.add_development_dependency "rake"
   s.add_development_dependency "contest", ">= 0.1.2"
