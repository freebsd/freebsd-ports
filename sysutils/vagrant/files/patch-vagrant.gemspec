--- vagrant.gemspec.orig	2014-12-02 14:36:28.268184765 -0700
+++ vagrant.gemspec	2014-12-02 14:37:17.140183285 -0700
@@ -15,11 +15,11 @@
   s.required_rubygems_version = ">= 1.3.6"
   s.rubyforge_project         = "vagrant"
 
-  s.add_dependency "bundler", ">= 1.5.2", "< 1.7.0"
+  s.add_dependency "bundler", ">= 1.5.2"
   s.add_dependency "childprocess", "~> 0.5.0"
   s.add_dependency "erubis", "~> 2.7.0"
   s.add_dependency "i18n", "~> 0.6.0"
-  s.add_dependency "listen", "~> 2.7.1"
+  s.add_dependency "listen", ">= 2.7.1"
   s.add_dependency "hashicorp-checkpoint", "~> 0.1.1"
   s.add_dependency "log4r", "~> 1.1.9", "< 1.1.11"
   s.add_dependency "net-ssh", ">= 2.6.6", "< 2.10.0"
