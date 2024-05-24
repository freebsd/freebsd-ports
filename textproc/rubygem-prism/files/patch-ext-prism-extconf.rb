--- ext/prism/extconf.rb.orig	2024-05-17 12:26:22 UTC
+++ ext/prism/extconf.rb
@@ -50,7 +50,7 @@ def make(env, target)
   Dir.chdir(File.expand_path("../..", __dir__)) do
     system(
       env,
-      RUBY_PLATFORM.include?("openbsd") ? "gmake" : "make",
+      (RUBY_PLATFORM.include?("freebsd") || RUBY_PLATFORM.include?("openbsd")) ? "gmake" : "make",
       target,
       exception: true
     )
