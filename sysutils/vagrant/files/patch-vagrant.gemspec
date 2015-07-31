--- vagrant.gemspec.orig	2015-07-24 11:06:28 UTC
+++ vagrant.gemspec
@@ -15,7 +15,7 @@ Gem::Specification.new do |s|
   s.required_rubygems_version = ">= 1.3.6"
   s.rubyforge_project         = "vagrant"
 
-  s.add_dependency "bundler", ">= 1.5.2", "<= 1.10.5"
+  s.add_dependency "bundler", ">= 1.5.2"
   s.add_dependency "childprocess", "~> 0.5.0"
   s.add_dependency "erubis", "~> 2.7.0"
   s.add_dependency "i18n", ">= 0.6.0", "<= 0.8.0"
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
   s.add_dependency "log4r", "~> 1.1.9", "< 1.1.11"
   s.add_dependency "net-ssh", ">= 2.6.6", "< 2.10.0"
   s.add_dependency "net-sftp", "~> 2.1"
-  s.add_dependency "net-scp", "~> 1.1.0"
+  s.add_dependency "net-scp", ">= 1.1.0"
   s.add_dependency "rb-kqueue", "~> 0.2.0"
   s.add_dependency "rest-client", ">= 1.6.0", "< 2.0"
   s.add_dependency "wdm", "~> 0.1.0"
@@ -32,7 +32,7 @@ Gem::Specification.new do |s|
   s.add_dependency "winrm-fs", "~> 0.2.0"
 
   # We lock this down to avoid compilation issues.
-  s.add_dependency "nokogiri", "= 1.6.3.1"
+  s.add_dependency "nokogiri", ">= 1.6.3.1"
 
   s.add_development_dependency "rake"
   s.add_development_dependency "rspec", "~> 2.14.0"
