--- ext/prism/extconf.rb.orig	2023-12-17 17:31:53 UTC
+++ ext/prism/extconf.rb
@@ -38,7 +38,7 @@ end
 # by this script.`
 def make(target)
   Dir.chdir(File.expand_path("../..", __dir__)) do
-    system("make", target, exception: true)
+    system("gmake", target, exception: true)
   end
 end
 
