--- specinfra.gemspec.orig	2016-07-06 07:27:32 UTC
+++ specinfra.gemspec
@@ -24,8 +24,6 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<net-scp>.freeze, [">= 0"])
       s.add_runtime_dependency(%q<net-ssh>.freeze, ["< 4.0", ">= 2.7"])
-      s.add_runtime_dependency(%q<net-telnet>.freeze, [">= 0"])
-      s.add_runtime_dependency(%q<sfl>.freeze, [">= 0"])
       s.add_development_dependency(%q<bundler>.freeze, ["~> 1.3"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.1.1"])
       s.add_development_dependency(%q<rspec>.freeze, [">= 0"])
@@ -33,8 +31,6 @@ Gem::Specification.new do |s|
     else
       s.add_dependency(%q<net-scp>.freeze, [">= 0"])
       s.add_dependency(%q<net-ssh>.freeze, ["< 4.0", ">= 2.7"])
-      s.add_dependency(%q<net-telnet>.freeze, [">= 0"])
-      s.add_dependency(%q<sfl>.freeze, [">= 0"])
       s.add_dependency(%q<bundler>.freeze, ["~> 1.3"])
       s.add_dependency(%q<rake>.freeze, ["~> 10.1.1"])
       s.add_dependency(%q<rspec>.freeze, [">= 0"])
@@ -43,8 +39,6 @@ Gem::Specification.new do |s|
   else
     s.add_dependency(%q<net-scp>.freeze, [">= 0"])
     s.add_dependency(%q<net-ssh>.freeze, ["< 4.0", ">= 2.7"])
-    s.add_dependency(%q<net-telnet>.freeze, [">= 0"])
-    s.add_dependency(%q<sfl>.freeze, [">= 0"])
     s.add_dependency(%q<bundler>.freeze, ["~> 1.3"])
     s.add_dependency(%q<rake>.freeze, ["~> 10.1.1"])
     s.add_dependency(%q<rspec>.freeze, [">= 0"])
