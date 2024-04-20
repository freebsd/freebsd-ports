--- ext/prism/extconf.rb.orig	2024-04-20 15:25:13 UTC
+++ ext/prism/extconf.rb
@@ -49,7 +49,7 @@ def make(target)
   Dir.chdir(File.expand_path("../..", __dir__)) do
     system(
       RbConfig::CONFIG.slice(*%w[SOEXT CPPFLAGS CFLAGS CC AR ARFLAGS MAKEDIRS RMALL]), # env
-      RUBY_PLATFORM.include?("openbsd") ? "gmake" : "make",
+      (RUBY_PLATFORM.include?("freebsd") || RUBY_PLATFORM.include?("openbsd")) ? "gmake" : "make",
       target,
       exception: true
     )
