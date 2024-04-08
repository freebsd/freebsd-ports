--- ext/prism/extconf.rb.orig	2024-04-06 20:48:24 UTC
+++ ext/prism/extconf.rb
@@ -45,7 +45,7 @@ def make(target)
 # by this script.`
 def make(target)
   Dir.chdir(File.expand_path("../..", __dir__)) do
-    system(RUBY_PLATFORM.include?("openbsd") ? "gmake" : "make", target, exception: true)
+    system((RUBY_PLATFORM.include?("freebsd") || RUBY_PLATFORM.include?("openbsd")) ? "gmake" : "make", target, exception: true)
   end
 end
 
